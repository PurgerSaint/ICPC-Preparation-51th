# 2252A.Boss Fight
[Rating](源于CList)723
[Tag]贪心
[Time]补题05:22
## 题目详情
You are fighting a boss with an unknown amount of health. You have a sequence of $n$ spell cards, where the $i$\-th card deals $a_i$ damage. You can rearrange your hand and play the cards in any order you choose.
The boss has an adaptive shield. If you ever play two cards in a row that deal the exact same amount of damage, the shield permanently activates. The card that triggers the shield still deals its normal damage, but all **subsequent** cards you play will deal $0$ damage.
Find the maximum total health the boss can have such that you will defeat him if you arrange and play your cards optimally.
**Input**
Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.
The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the number of spell cards.
The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 1000$) — the damage dealt by each card.
**Output**
For each test case, output a single integer — the maximum total health the boss can have such that you will defeat him.
## 提交详情
- 提交时间:(比赛时)23:11 状态:WA 详细状态:`Wrong answer on pretest 3`
> 题目要求是使得BOSS血量最大化，那我就尽量使得所有伤害高的技能尽可能多的释放，使得断点位于小的  
那我就先统计所有数字(技能伤害)出现的次数进行压缩，然后根据伤害升序排序，再做次数的前缀和  
接着按伤害降序遍历，根据前缀和得到前面可用的为`cnt[i-1]+1`，如果当前前面的可用都无法插空，就退出  
再记录次数债  
即对于当前`c`次的伤害，要完全发挥出来，至少需要前面`c+1`张插空以使得完全发挥而出，故记录次数债为`c+1`  
枚举接下来的伤害时，先处理次数债，再处理其本身
- 提交时间:(比赛时)00:10 状态:WA 详细状态:`Wrong answer on pretest 3`
> 第一次提交时我压缩没有按数字进行压缩，而是按位置进行压缩，使得可能出现多个位置同数字出现
- 提交时间:15:28 状态:AC 详细状态:`-`
> 经*GPT*解读后，我发现我的问题在于安排过于仔细了  
两个重复技能产生护盾，这个重复的技能必然在次数最多的技能中产生  
那么只需关注这个次数最多的技能即可，其他的技能都可以作为`other`  
最后根据这个次数最多的技能可使用次数($max(other+2, cnt)$)在总和减去损失即可

# 2252B.Always Changing
[Rating](源于CList)1055
[Tag]贪心、数学、字符串处理
[Time]补题22:08
## 题目详情
You are given a binary string $s$$s$ of length $n$$n$.
A string is called alternating if no two adjacent characters are the same. For example, 0101, 1, and 01 are alternating, but 0110 is not.
You want to transform $s$$s$ into an alternating string by performing the following operation any number of times (possibly zero):
-   Choose any character currently in the string and delete it.
However, your sequence of operations must follow a rule: the characters you delete must strictly alternate. This means if the last character you deleted was 0, the next character you delete must be 1, and vice versa. Your very first deleted character can be either 0 or 1.
Find the minimum number of operations required to make $s$$s$ an alternating string. If it is impossible to achieve this, output $−1$$-1$.
**Input**
Each test contains multiple test cases. The first line contains the number of test cases $t$$t$ ($1≤t≤104$$1 \le t \le 10^4$). The description of the test cases follows.
The first line of each test case contains a single integer $n$$n$ ($1≤n≤2⋅105$$1 \le n \le 2 \cdot 10^5$) — the length of the string $s$$s$.
The second line of each test case contains the binary string $s$$s$ of length $n$$n$, consisting only of the characters 0 and 1.
It is guaranteed that the sum of $n$$n$ over all test cases does not exceed $2⋅105$$2 \cdot 10^5$.
**Output**
For each test case, output a single integer — the minimum number of operations required to make $s$$s$ an alternating string, or $−1$$-1$ if it is impossible.
## 提交详情
- 提交时间:(比赛时)23:47 状态:WA 详细状态:`Wrong answer on pretest 2`
> 我先行统计了以下信息：
> 1. 所有连续出现中需要删除的`1`总数，记为`x`；所有连续出现中需要删除的`0`总数，记为`y`  
> 2. 单个出现(已符合条件)的`1`数量`cnt1`和`0`数量`cnt0`  
> 3. 连续出现中剩下单个`1`的个数`b1`和单个`0`的个数`b0`  
> - 然后根据条件判断，这里用`1`做例子，`0`同理:  
先判断剩余量`x-y`是否能被剩下的`0`消去，即`(x - y) > (cnt0 + b0) + 1`  
再判断剩余量如果都被剩余的`0`(`cnt0`)全消去了，即当前没有`0`了，但`1`还有剩余(`cnt1`大于0)，则必然成块，且无法删除(消去`x`的最后一步就是删除1)，故也不行  
最后直接返回答案`2 * y + (x - y) * 2 - ((x - y) > 0)`
- 提交时间:(比赛时)00:06 状态:WA 详细状态:`Wrong answer on pretest 3`
> 我列了许多样例来寻找边界点，包括删除后会重新构成`1`这样的`0111011`  
修改了第一次提交中的判断，剩余量需要包含连续出现的单个，即`cnt0 + b0`  
然后剩余也是要包含单个`1`(`cnt1 + b1`)，且必须满足`b1 > 1 || cnt1 > 0`
- 提交时间:16:07 状态:AC 详细状态:`-`
> 经*GPT*解读后，我只需留下:
> 1. 所有连续出现中需要删除的`1`总数，记为`x`；所有连续出现中需要删除的`0`总数，记为`y`  
> 2. 删除后最终要呈现的交替段，段中`1`的个数`cnt1`，`0`的个数`cnt0`  
> 唯一不可行的条件，即原段中`1`和`0`的个数相差超过2(这是我没想到的)  
因为删除的`0`和`1`最多相差1，最终交替段中的`0`和`1`也最多相差1  
然后删除量就是按我思路那样，先是两倍小的(交替删除)，然后剩下的两倍减一，即需要额外的`1`和`0`来交替删除，最少需要剩余量减一的额外量来帮助删除