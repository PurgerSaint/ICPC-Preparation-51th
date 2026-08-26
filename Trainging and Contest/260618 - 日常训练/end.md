# [435.无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals)

## 题目介绍
给定一个区间的集合`intervals`，其中`intervals[i] = [starti, endi]`。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
**注意**只在一点上接触的区间是**不重叠的**。例如`[1, 2]`和`[2, 3]`是不重叠的。

## 第一次提交 (状态:AC)
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a.back() < b.back();
        });
        int ans = 1, l = intervals[0][1], n = intervals.size();
        for (int i = 1; i < n; i++) {
            int& start = intervals[i][0], end = intervals[i][1];
            if (start >= l) {
                ans++;
                l = end;
            }
        }
        return n - ans;
    }
};
```
> 本题关键是根据区间右边界进行排序  
使得所有区间内不重叠区间最多，只要使得一小部分区间内不重叠区间最多即可
对于每个区间，只要不和上一个已选的区间冲突，就可以选择

# [630.课程表 III](https://leetcode.cn/problems/course-schedule-iii)

# 题目介绍
这里有`n`门不同的在线课程，按从`1`到`n`编号。给你一个数组`courses`，其中`courses[i] = [durationi, lastDayi]`表示第`i`门课将会**持续**上`durationi` 天课，并且必须在不晚于 `lastDayi` 的时候完成。   
你的学期从第 `1` 天开始。且不能同时修读两门及两门以上的课程。   
返回你最多可以修读的课程数目。

## 第一次提交 (状态:WA)
```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            return a.back() - a.front() < b.back() - b.front();
        });
        int ans = 0, use = 0;
        for (vector<int>& e: courses) {
            if (e.back() < e.front()) continue;
            if (use + e.front() > e.back()) continue;
            use += e.front(); 
            ans++;
        }
        return ans;
    }
};
```
> 试图用每个课程最晚开始时间进行排序，但这样可能会选择不符合的或者时间过长的课程

## 第二次提交 (状态:WA)
```cpp
class Solution {
public:
    struct ke {
        int duration;
        int end;
        ke(int d, int e): duration(d), end(e) {}
    };
    struct cmp {
        bool operator()(const ke& a, const ke& b)  {
            return a.end > b.end;
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            if (a.back() == b.back()) return a.front() < b.front();
            return a.back() < b.back();
        });
        priority_queue<ke, vector<ke>, cmp> pq;
        int use = 0;
        for (vector<int>& e: courses) {
            if (e.back() <= e.front()) continue;
            int& duration = e.front(), end = e.back();
            if (use + duration <= end) {
                use += duration;
                pq.push({duration, end});
            } else if (!pq.empty() && pq.top().duration > duration) {
                use -= pq.top().duration - duration;
                pq.pop();
                pq.push({duration, end});
            }
        }
        return pq.size();
    }
};
```
> 还是在第一次提交的基础上，试图通过自建结构体来确保正确

## 第三次提交 (状态:AC)
```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){
            if (a.back() == b.back()) return a.front() < b.front();
            return a.back() < b.back();
        });
        priority_queue<int> pq;
        int use = 0;
        for (vector<int>& e: courses) {
            if (e.back() < e.front()) continue;
            int& duration = e.front(), end = e.back();
            if (use + duration <= end) {
                use += duration;
                pq.push(duration);
            } else if (!pq.empty() && pq.top() > duration) {
                use -= pq.top() - duration;
                pq.pop();
                pq.push(duration);
            }
        }
        return pq.size();
    }
};
```
> 选了更多短时间的课，就代表能选的课就越多  
当前课如果能选(未超出当前所有选择课的总时间)，就选当前的课
否则就从已选课程中选择一个最大的课程进行替换
选择最大课程用大根堆(优先队列降序版)

# [1344.时钟指针的夹角](https://leetcode.cn/problems/angle-between-hands-of-a-clock)

## 题目介绍
给你两个数`hour`和`minutes`。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60单位制）。

## 第一次提交 (状态:WA)
```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = hour % 12 * 30 + minutes / 60.0 * 30;
        // cout << (hour % 12) << " " << (minutes / 60.0) << "\n";
        double minutes_angle = minutes * 6;
        // cout << "hour_angle:" << hour_angle << " " << "minutes_angle:" << minutes_angle << "\n";
        double ans = abs(hour_angle - minutes_angle);
        if (ans - 180 > 1e9)
            ans = min(ans, 60 - max(hour_angle, minutes_angle) + min(hour_angle, minutes_angle));
        return ans;
    }
};
```
> 这里我想着先寻找两个指针中两个角度(一个是跨越0点的，另一个是相反的)，然后取小的那个作为答案即可  
但是我忘了总体角度是360而不是总时钟的60

## 第二次提交 (状态:AC)
```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = hour % 12 * 30 + minutes / 60.0 * 30;
        // cout << (hour % 12) << " " << (minutes / 60.0) << "\n";
        double minutes_angle = minutes * 6;
        // cout << "hour_angle:" << hour_angle << " " << "minutes_angle:" << minutes_angle << "\n";
        double ans = abs(hour_angle - minutes_angle);
        if (ans - 180 > 1e-9)
            ans = min(ans, 360 - max(hour_angle, minutes_angle) + min(hour_angle, minutes_angle));
        return ans;
    }
};
```
> 修正了角度问题，且修改了浮点数大小比较的错误，应该是`1e-9`而不是`1e9`

# [242.有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

## 题目介绍
给定两个字符串`s`和`t`，编写一个函数来判断`t`是否是`s`的字母异位词。

## 第一次提交 (状态:AC)
### 哈希法
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c - 'a']++;
        for (char c: t) {
            if (cnt[c - 'a'] <= 0) return false;
            cnt[c - 'a']--;
        }
        return true;
    }
};
```
> 前一个字符串记录下每个字母出现的次数，后一个字符串逐个遍历寻找是否有可用字符即可
### 排序法
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        ranges::sort(s);
        ranges::sort(t);
        return s == t;
    }
};
```
> 只要排序后大小相等即可