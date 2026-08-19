$ErrorActionPreference='Stop'
$path='F:\Desktop\Kindle\ICPC\task.md'
$lines=[IO.File]::ReadAllLines($path)

# ---- 定位表头与表尾 ----
$h=-1
for($k=0;$k -lt $lines.Count;$k++){ if($lines[$k] -match '^\|\s*日期\s*\|'){ $h=$k; break } }
if($h -lt 0){ throw 'header not found' }
$tableEnd=$h
for($k=$h+1;$k -lt $lines.Count;$k++){ if($lines[$k].StartsWith('|')){ $tableEnd=$k } else { break } }

# ---- 解析行：当前为 9 列（含 三维需求/优先分），剥掉优先分，保留三维 ----
$rows=New-Object System.Collections.Generic.List[object]
$idx=0
for($k=$h+1;$k -le $tableEnd;$k++){
  $idx++
  $line=$lines[$k]
  if($line -match '^\|[\s:\-]+\|$'){ continue }
  $c=@(); foreach($s in $line.Split('|')){ $c+=$s.Trim() }
  if($c.Count -ne 11){ throw ("bad row parts={0} line={1}: {2}" -f $c.Count,($k+1),$line) }
  # c[1..9] = 日期,来源,题目标题,算法类型,得分,关联度,三维,优先分,尝试记录 → 去掉 c[8]
  $rows.Add([pscustomobject]@{ date=$c[1]; idx=$idx;
    out=('| '+($c[1],$c[2],$c[3],$c[4],$c[5],$c[6],$c[7],$c[9] -join ' | ')+' |') })
}

# ---- 排序：回到日期降序（同日期保持现有相对顺序） ----
$sorted=$rows | Sort-Object -Property @{e='date';d=$true},@{e='idx';a=$true}

# ---- 重建文件 ----
$pre=New-Object System.Collections.Generic.List[string]
for($k=0;$k -lt $h;$k++){
  if($lines[$k] -match '^> 排序规则'){ continue }   # 删掉我加的、导致渲染失效的 glued 引用行
  $pre.Add($lines[$k])
}
while($pre.Count -gt 0 -and $pre[$pre.Count-1] -eq ''){ $pre.RemoveAt($pre.Count-1) }

$out=New-Object System.Collections.Generic.List[string]
$out.AddRange($pre)
$out.Add('')
$out.Add('| 日期 | 来源 | 题目标题 | 算法类型 | 题目得分 | 网赛关联度 | 三维需求(读/模/暴) | 尝试记录 |')
$out.Add('| :--- | :--- | :--- | :--- | :---: | :---: | :---: | :--- |')
foreach($r in $sorted){ $out.Add($r.out) }
for($k=$tableEnd+1;$k -lt $lines.Count;$k++){ $out.Add($lines[$k]) }

[IO.File]::WriteAllLines($path,$out,[Text.UTF8Encoding]::new($true))  # 带 BOM，防编辑器误判编码
Write-Output ("rows={0}" -f $sorted.Count)
Write-Output '--- head ---'
$out[($pre.Count)..($pre.Count+6)] | ForEach-Object { $_ }
