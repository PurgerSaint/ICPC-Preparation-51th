# 2025 ICPC I 日志

# 赛时通过数：

```cpp
A 1594/6897 B 1976/3258
C 356/1289  D 462/1781
E 0/67      F 61/1033
G 2146/3462 H 18/90
I 1370/3690 J 127/281
K 12/48     L 1/85
M 694/5398
```

---

# G. Sorting

You are given m pairs $(a_i , b_i)$, $1 ≤ a_i < b_i ≤ n$, we define the following program to sort a permutation:

```python
for i = 1 to 1000000000000000000:
  for j = 1 to m:
    if p [a[j]] > p[b[j]]:
      swap (p[a[j]], p[b[j]])
```

Check whether it can sort every permutation  $p$ of length $n$.

Input

The first line contains two integers $n$ and $m (2 ≤ n ≤ 2 × 105 , 1 ≤ m ≤ 2 × 105 )$. The following are m lines, every line contains two integers $(a_i , b_i) (1 ≤ ai < bi ≤ n)$.

Output

Output Yes if it can sort every permutation of length $n$, and No if it cannot.

> 赛时题目理解：给与m对，遵循一个排序规则
请检查他是否能排成n长度的排列组合p
即最终是否有n个有序的pair键值对
将permutation翻译成排列组合，得到题目要求为寻找是否存在一个排序后长度为n的排列组合p，即是否存在排序后有n个有序pair。
> 

> 赛时第一次思考，每次比较每一对中的键和值，若键比值大就交换
此时把p当做pair（即每一对），a[j]和b[j]就是每一对的键和值
但想到：只排序没有删除，最后得到的还是m长度，单论m和n大小比较不成立
> 

> 赛时队友提出：是否需要拼凑成(1,2)(2,3)....(n-1,n)
遭我否决：单排序后长度不变，最终还是落到m和n的大小比较
> 

> 赛时第二次思考，是否每个a[j]和b[j]就是每一对的下标
即每次比较第a[j]对和第b[j]对，使得最终形成一个有序序列
（依据pair比较规则）
但排序前后长度不变，还是落到m和n长度比较
此时想记录cnt次数来看是否如此（测试未通过，未提交）
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, m; cin>>n>>m;
    vector<pair<int,int>> x;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        x.push_back({a, b});
    }
    int cnt = 0;
    for (pair<int,int>& t : x) {
        if (x[t.first - 1] > x[t.second - 1]) {
            swap(x[t.first - 1], x[t.second - 1]);
            cnt++;
        }
    }
    cout<< cnt == n ? "Yes" : "No";
    return 0;
}

```

> 赛时第二次尝试寻找，寻找是否有完整的(1,2)(2,3)....(n-1,n)
提交后报错，因为这个无法检查是否最后的序列是否连续
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    set<int> x;
    int n, m; cin>>n>>m;
    vector<bool> flag(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        if (a == n) flag[b] = true;
        else if(b == n) flag[a] = true;
    }
    for (int i = 1; i < n; i++)
        if (!flag[i]) {
            cout<<"No";
            return 0;
        }
    cout<<"Yes";
    return 0;
}

```

> 赛后看题解分析，他给与的是m对下标，排序规则是前一个下标对应的数若大于后一个下标对应的数就进行交换
就是冒泡排序，问你使用这些下标，是否能排序出一个长度为n的序列（亦或是数组）？
> 

> 错误1：最终是序列（数组）而非多少个pair
错误2：p在此指向的是数组
错误3：意识到a_i<b_i<=n，但只惦记n和m的关系，没有想到数组中的关系
> 

> 赛后第一次提交，错误，因为没想到可能存在(1,4)(3,4)(4,5)这种非连续的
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    set<int> x;
    int n, m; cin>>n>>m;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        if (b - a == 1) {
            cnt[a]++;
            cnt[b]++;
        }
    }
    if (cnt[1] == 0 || cnt[n] == 0) {
        cout<<"No";
    } else {
        int i = 2;
        for (; i < n - 1; i++)
            if (cnt[i] < 2) break;
        if (i != n - 1) cout<<"No";
        else cout<<"Yes";
    }
    return 0;
}

```

> 赛后第二次提交，还是只顾着寻找是否有从1到n的完整序列了，没有找到是否连续
> 

```cpp
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
    }

    if (count == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

```

> 赛后第三次提交，使用set寻找完整序列，通过
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, m; cin>>n>>m;
    set<pair<int,int>> x;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        x.insert({a, b});
    }
    for (int i = 1; i < n; i++) {
        if (!x.count({i, i + 1})) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

```

> map版本
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, m; cin>>n>>m;
    map<pair<int,int>,int> x;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        x.insert({{a, b}, 0});
    }
    for (int i = 1; i < n; i++) {
        if (!x.count({i, i + 1})) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

```

> 哈希表版本
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, m; cin>>n>>m;
    // 警醒1：值不能设置为int，因为对应键只有唯一值
    unordered_map<int,unordered_set<int>> hash;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        hash[a].insert(b);
    }
    for (int i = 1; i < n; i++) {
        if (hash.find(i) == hash.end() || hash[i].find(i+1) == hash[i].end()) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

```

# **B. Creating Chaos**

As a Cappuccino Assassino, you despise order. You want everything in the world to be as chaotic as possible.
In front of you are n cups of cappuccino, arranged in a line and numbered from 1 to n. You wish to drink k of them, so that the remaining cappuccinos are as disordered as possible.
Suppose the positions of the remaining cappuccinos are a1, a2, . . . , an−k. The degree of order is definedas:$\sum_{i=1}^{n-k} \sum_{j=i+1}^{n-k} =gcd(|a_i − a_j |, n)$, where gcd represents the greatest common divisor.
You need to minimize this degree of order and output the sequence of cappuccinos you choose to drink.
If there are multiple answers, you can output any one of them.
Input
Given two integers n, k (1 ≤ k ≤ n ≤ 1000), separated by a space.
Output
k integers, representing the indices of the cappuccinos that are drunk.

> 赛时提醒：答案不唯一，输出任意一种答案即可
> 

> 赛时理解：给与n个酒杯，可以喝其中的k杯
要求剩余的n-k杯的序号满足公式的最小值
> 

> 赛时第一次尝试，使用DFS找到数组中所有n-k大小的子数组，并计算他们的公式值
最后对这些子数组按公式值大小升序，根据第一个最小公式值的子数组
输出不在子数组的剩余k个坐标即可（提交并通过）
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
vector<int> a;
vector<pair<int,vector<int>>> res;
void dfs(vector<int>& path, int n, int k, int i) {
    if (path.size() == n - k) {
        int sum = 0;
        for (int i = 0; i < n - k; i++)
            for (int j = i + 1; i < n - k; i++)
                sum += gcd(abs(path[i] - path[j]), n);
        res.push_back({sum, path});
        return;
    }
    path.push_back(a[i]);
    dfs(path, n, k, i + 1);
    path.pop_back();
}
int main(){
    IOS;
    int n, k; cin>>n>>k;
    a = vector<int>(n);
    for (int i = 0; i < n ; i++)
        a[i] = i+1;
    vector<int> path;
    dfs(path, n, k, 0);
    sort(res.begin(), res.end(), [](pair<int,vector<int>>& a, pair<int,vector<int>>& b){
        return a.first < b.first;
    });
    unordered_set<int> hash(res[0].second.begin(), res[0].second.end());
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (hash.find(i) == hash.end())
            ans.push_back(i);
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<(i != ans.size() - 1 ? " " : "");
    return 0;
}
```

> 赛后第一次尝试，发现赛时的想法—直接输出1到k也能通过
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, k; cin>>n>>k;
    for (int i = 1; i <= k; i++)
        cout<<i<<(i != k ? " " : "");
    return 0;
}
```

> 赛后分析：
赛时1到k的直觉想法没想到就是正确的，但是不完整
使得选取的n-k个数满足$\sum_{i=1}^{n-k} \sum_{j=i+1}^{n-k} =gcd(|a_i − a_j |, n)$最小
只要使得$gcd(|a_i − a_j |, n)$最小，整体即最小（贪心）
设$|a_i − a_j|$是间隔，当且仅当间隔和n的最大公因数最小时，整体最小
间隔必定小于n，则如果间隔不是n的因数，则此时他们的最大公因数最小
那么就是n无法整除间隔时最小，此时又可知他们的最大公因数是1
不用二分来进行猜测，所以以1为间隔，取出n-k个数，输出剩余k个数即可
> 

# **A. Who Can Win**

In ICPC contests, the scoreboard is frozen during the last hour. Submissions made during the freeze are shown with result Unknown.
You are given multiple submission logs from old ICPC contests. However, the results of submissions made after the freeze are hidden. For each contest, determine all teams that could possibly be the champion.
**Rules**
Each submission is represented as a tuple:
(teamname, problemid,time,result)
• **teamname**: a string of at most 10 characters, consisting of uppercase or lowercase letters and digits.It identifies the team that made the submission.
• **problemid**: a single uppercase letter (A–Z) that identifies the problem being attempted.
• time: an integer between 0 and 299, inclusive, representing the number of minutes from the start of the contest.
• **result**: the outcome of the submission:
– **Accepted**: the submission correctly solves the problem.
– **Rejected**: the submission does not solve the problem.
– **Unknown**: the submission result is unknown because it was made after the scoreboard was frozen.
– **Note: a submission has result Unknown if and only if its time ≥ 240.**
For a contest where all results are known, a team’s score is determined by:

1. **Solved problems**: the number of problems for which this team has at least one Accepted
submission.
2. Penalty time: the total time consumed by all problems that the team solved (0 if none).
• For each solved problem, calculate the time as follows:
(a) Take the submission time of the team’s first Accepted submission for that problem.
(b) Add 20 minutes for each of the team’s submissions to the same problem that **occurred earlier in time** and had result Rejected.
• A submission is considered earlier than another if its submission time is smaller.
• **Note: a team will never make more than one submission in the same minute.**

A champion team is one with the highest number of solved problems and, among them, the smallest penalty time. Multiple champion teams may exist if they have the same number of solved problems and the same penalty time.
Please determine all teams that could possibly be champions for any scenario where each Unknown submission is replaced independently by either Accepted or Rejected.
Input
The first line contains an integer T (1 ≤ T ≤ 10000) — the number of contests.
For each contest:
• The first line contains an integer s (1 ≤ s ≤ 105) — the number of submissions for this contest.
• Each of the next s lines describes a submission in the format: teamname problemid time result
It is guaranteed that:
• T ≤ 10000 and Ps ≤ 105 over all contests.
• teamname consists of at most 10 uppercase/lowercase letters and digits.
• problemid is a single uppercase letter (A–Z).
• time is an integer between 0 and 299, inclusive.
• result is Accepted, Rejected, or Unknown.
• Each contest has at least one Accepted submission.
• A team will never make more than one submission in the same minute.
Output
Output T lines, one for each contest. Each line contains all team names that could possibly be champions for that contest, **in lexicographical order**, separated by spaces.

> 赛时分析：有正确、错误、未知三种状态，首次正确就会更新当前时间，错误就会加20分钟，未知是在240分钟后，有正确和错误的可能性，输出最后有可能的得冠军的队伍
> 

> 疑惑点：分析样例可知前二题数和时间不同，为何是输出前两个呢？
> 

> 直接假设未知状态为正确的，首次正确就会更新时间，错误就会罚时，最后按字典序排序输出前两个队伍名即可（第一次提交，错误）
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
struct State {
    string name;
    unordered_set<char> ac;
    int time;
    int wa;
    int u;
    State(string s, int n) : name(s), time(n), wa(0), u(0) {}
    bool operator<(const State& other) const {
        if (ac.size() == other.ac.size()) return time < other.time; 
        return ac.size() > other.ac.size();
    }
};
void solve(){
    vector<State> rank;
    unordered_map<string, int> hash;
    int n; cin>>n;
    for (int i = 0; i < n; i++) {
        string name;int mark;
        string s;char t;
        cin>>name>>t>>mark>>s;

        int index;
        if (hash.find(name) == hash.end()) {
            rank.push_back(State(name, 0));
            index = rank.size() - 1;
            hash[name] = index;
        } else index = hash[name];

        State& g = rank[index];
        if (s == "Rejected") {
            g.wa++;
        } else {
            if (g.ac.find(t) == g.ac.end() && g.time < mark) g.time = mark;
            g.ac.insert(t);
        }
    }
    for (State& t : rank)
        t.time += t.wa * 20;
    sort(rank.begin(), rank.end(), [](State& a, State& other){
        if (a.ac.size() == other.ac.size()) return a.time < other.time; 
        return a.ac.size() > other.ac.size();
    });
    vector<string> res;
    for (int i = 0; i < rank.size(); i++) {
        if (res.size() == 2) break;
        if (!rank[i].ac.empty()) res.push_back(rank[i].name);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<(i != res.size() - 1 ? " " : "");
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        solve();
        cout<< (t == 0 ? "" : "\n");
    }
    return 0;
}
```

> 题解分析：对于Unknown，找到每一队的最好成绩（Unknown全对）和最坏成绩（全错）
> 

> 错误1：选取Unknown不用选取最后一次，选取第一个Unknown作为AC时间即可
> 

> 错误2：未通过的题目不用计算罚时
> 

> 补题第一次提交，方法太暴力直接TL，需要优化
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
struct State {
    string name;
    char t;
    int time;
    string state;
    State(string s, char c, int ti, string st) : name(s), time(ti), t(c), state(st) {}
};
struct rk {
    string name;
    int act;
    vector<int> ac;
    vector<int> wa;
    vector<int> un;
    vector<int> unt;
    rk(string s) : name(s), act(0), ac(26, -1), un(26, 0), unt(26, -1), wa(26, 0) {}
};
struct sub {
    string name;
    int ac;
    int time;
    sub(string n, int a, int t) : name(n), ac(a), time(t) {}
    bool operator<(const sub& other) const {
        if (ac == other.ac) return time < other.time;
        return ac > other.ac;
    }
};
void solve(){
    int k; cin>>k;
    /* 先输入全部日志数据 */
    vector<string> list;
    set<string> l;
    vector<State> log;
    for (int i = 0; i < k; i++) {
        string name, state;
        char t; int time;
        cin>>name>>t>>time>>state;
        log.push_back(State(name, t, time, state));
        if (l.find(name) != l.end()) continue;
        l.insert(name);
        list.push_back(name);
    }
    sort(log.begin(), log.end(), [](State& a, State& b){
        return a.time < b.time;
    });

    /* 再分析所有日志数据 */
    vector<rk> r;
    unordered_map<string, int> hash;
    for (State& p : log) {
        string& name = p.name, state = p.state;
        char t = p.t; int time = p.time;

        if (hash.find(name) == hash.end()) {
            r.push_back(rk(name));
            hash[name] = r.size() - 1;
        }
        rk& g = r[hash[name]];

        int id = t - 'A';
        if (g.ac[id] != -1) continue;

        if (state == "Accepted") {
            g.ac[id] = time;
            g.act++;
        } else if (state == "Rejected") {
            g.wa[id]++;
        } else{
            // 只记录第一次unkonw时间
            if (g.un[id] == 0) g.unt[id] = time;
            g.un[id]++;
        } 
    }

    // 假设当前对，其余未知全错
    // 提取每一个可能为第一的
    set<sub> rank;
    vector<string> res;
    int size = list.size();
    for (int i = 0; i < size; i++) {
        rank.clear();
        rk& g = r[hash[list[i]]];
        int cnt = 0, time = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1) time += g.ac[j] + g.wa[j] * 20;
            else if (g.unt[j] != -1) {
                time += g.unt[j] + g.wa[j] * 20;
                cnt++;
            }
        }
        rank.insert(sub(g.name, g.act + cnt, time));

        for (int j = 0; j < size; j++) {
            if (i == j) continue;
            rk& b = r[hash[list[j]]];
            int bt = 0;
            for (int x = 0; x < 26; x++) {
                if (b.ac[x] != -1) bt += b.ac[x] + b.wa[x] * 20;
            }
            rank.insert(sub(b.name, b.act, bt));
        }

        int k = -1;
        auto it = find_if(rank.begin(), rank.end(), [&](const sub& s){ return s.name == list[i]; });
        if (it != rank.end()) {
            k = distance(rank.begin(), it);
            if (k == 0) res.push_back(list[i]);
        }
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<(i != res.size() - 1 ? " " : "");
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        solve();
        cout<< (t == 0 ? "" : "\n");
    }
    return 0;
}
```

> 先行计算最坏情况，然后最好情况跟每个最差情况比较，如果比每个最差都好就代表冠军
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
struct State {
    string name;
    char t;
    int time;
    string state;
    State(string s, char c, int ti, string st) : name(s), time(ti), t(c), state(st) {}
};
struct rk {
    string name;
    int act;
    vector<int> ac;
    vector<int> wa;
    vector<int> unt;
    rk(string s) : name(s), act(0), ac(26, -1), unt(26, INT_MAX), wa(26, 0) {}
};
struct sub {
    string name;
    int ac;
    int time;
    sub(string n, int a, int t) : name(n), ac(a), time(t) {}
};
void solve(){
    int k; cin>>k;
    /* 先输入全部日志数据 */
    vector<string> list;
    set<string> l;
    vector<State> log;
    for (int i = 0; i < k; i++) {
        string name, state;
        char t; int time;
        cin>>name>>t>>time>>state;
        log.push_back(State(name, t, time, state));
        if (l.find(name) != l.end()) continue;
        l.insert(name);
        list.push_back(name);
    }
    sort(log.begin(), log.end(), [](State& a, State& b){
        return a.time < b.time;
    });

    /* 再分析所有日志数据 */
    vector<rk> r;
    unordered_map<string, int> hash;
    for (State& p : log) {
        string& name = p.name, state = p.state;
        char t = p.t; int time = p.time;

        if (hash.find(name) == hash.end()) {
            r.push_back(rk(name));
            hash[name] = r.size() - 1;
        }
        rk& g = r[hash[name]];

        int id = t - 'A';
        if (g.ac[id] != -1) continue;

        if (state == "Accepted") {
            g.ac[id] = time;
            g.act++;
        } else if (state == "Rejected") {
            g.wa[id]++;
        } else if (g.unt[id] == INT_MAX) {
            // 只记录第一次unkonw时间
            g.unt[id] = time;
        } 
    }

    // 假设当前对，其余未知全错
    // 提取每一个可能为第一的
    vector<sub> rank;
    int size = list.size();
    for (int i = 0; i < size; i++) {
        rk& g = r[hash[list[i]]];
        int time = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1)
                time += g.ac[j] + g.wa[j] * 20;
        }
        rank.push_back(sub(g.name, g.act, time));
    }
    auto better = [](sub& a, sub& b){
        if (a.ac == b.ac) return a.time < b.time;
        return a.ac > b.ac;
    };

    vector<string> res;
    for (int i = 0; i < size; i++) {
        rk& g = r[hash[list[i]]];
        int time = 0, cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (g.ac[j] != -1)
                time += g.ac[j] + g.wa[j] * 20;
            else if (g.unt[j] != INT_MAX) {
                cnt++;
                time += g.unt[j] + g.wa[j] * 20;
            }
        }
        sub t = sub(g.name, g.act + cnt, time);

        bool flag = false;
        for (sub& p : rank) {
            if (p.name == t.name) continue;
            if (better(p, t)) {
                flag = true;
                break;
            }
        }
        if (!flag) res.push_back(g.name);
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<(i != res.size() - 1 ? " " : "");
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        solve();
        cout<< (t == 0 ? "" : "\n");
    }
    return 0;
}
```

# I.Knapsack Problem

Given an undirected graph with n vertices and m edges, each edge holds an item with weight wi. Xiao S has a compulsion: every time he traverses an edge, he must put the item on that edge into his backpack.The backpack has a capacity V . Initially, he starts with a new backpack. If the remaining capacity of the current backpack is insufficient to carry wi, he switches to a new backpack (discarding the old one).For each starting vertex from 1 to n, Xiao S chooses a path to reach a designated vertex T. Your task is to determine the minimum number of backpacks needed for each starting vertex to reach T. If it is impossible to reach T, output −1.
Input
The first line contains four integers n, m, V , and T (1 ≤ n, m, V ≤ 105, 1 ≤ T ≤ n).
The following m lines contain three integers each; the i-th line contains three integers xi, yi, and wi,representing an edge between xi and yi with an item of weight wi. It is guaranteed that 1 ≤ xi, yi ≤ n and 1 ≤ wi ≤ V .
Output
Output a single line with n integers; the i-th integer is the minimum number of backpacks needed when starting from vertex i. If T is unreachable, output −1。

> 赛时分析：一个无向图有n个点和m条边，每条边还有w的物品。给与v容量的背包，从某个点出发拾取物品，若背包容量不够就装到新的背包。请问从每个点到目标点T所需要的最小背包数量是多少？
> 

> 使用Dijkstra找到每个点到目标点的单源最短路径，获得每个点到目标点获取的最少物品权值，然后再计算每个路径所需要的背包数即可
> 

> 第一次提交，超时，加入优化，当遇到目标点时直接返回权值，当前点直接算1
> 

> 第二次提交，依旧超时
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int target = 0;
struct State {
    int node, dis;
    State(int n, int d) : node(n), dis(d) {}
    bool operator<(const State& other) const {
        return dis > other.dis;
    }
};
vector<vector<pair<int,int>>> mp;
int Dijkstra(int n, int start) {
    vector<int> dis(n + 1, -1);
    priority_queue<State> pq;
    pq.push(State(start, 0));
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int v = t.node, w = t.dis;
        if (dis[v] != -1) continue;
        if (v == target) return w;
        dis[v] = w;
        for (pair<int,int>& p : mp[v]) {
            int y = p.first, w2 = w + p.second;
            if (dis[y] == -1) pq.push(State(y, w2));
        }
    }
    return -1;
}
int main(){
    IOS;
    int n, m, v; cin>>n>>m>>v>>target;
    mp = vector<vector<pair<int,int>>>(n + 1);
    for (int i = 0 ; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        int t;
        if (i == target){
            t = 1;
        } else if (mp[i].empty()) {
            t = -1;
        } else {
            int k = Dijkstra(n, i);
            t = k / v;
            if (k % v != 0) t++;
        }
        cout<<t<<(i != n ? " " : "");
        
    }
    return 0;
}
```

> 赛后第一次补题提交，未通过。之前我是所有点到目标点的计算，那样会很大，那要是我直接使用Dijkstra从目标点出发到每一个点，岂不是时间节省一大半！
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int target = 0, mb;
struct State {
    int node, dis;
    State(int n, int d) : node(n), dis(d) {}
    bool operator<(const State& other) const {
        return dis > other.dis;
    }
};
vector<vector<pair<int,int>>> mp;
void Dijkstra(int n, int start) {
    vector<int> dis(n + 1, -1);
    priority_queue<State> pq;
    pq.push(State(start, 0));
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int v = t.node, w = t.dis;
        if (dis[v] != -1) continue;
        dis[v] = w;
        for (pair<int,int>& p : mp[v]) {
            int y = p.first, w2 = w + p.second;
            if (dis[y] == -1) pq.push(State(y, w2));
        }
    }
    for (int i = 1; i <= n; i++) {
    	int t = 0;
        if (target == i) {
            t = 1;
        } else if (mp[i].empty()) {
        	t = -1;
		} else {
            t = dis[i] / mb;
            if (dis[i] % mb != 0) t++;
        }
        cout<<t<<(i != n ? " " : "");
    }
}
int main(){
    IOS;
    int n, m; cin>>n>>m>>mb>>target;
    mp = vector<vector<pair<int,int>>>(n + 1);
    for (int i = 0 ; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    Dijkstra(n, target);
    return 0;
}
```

> 第二次提交，将原有维护的价值总量换成背包数和当前背包剩余容量，因为在原有情况下，2和6虽然是在容量为5的情况下为两个背包，但是这样是折断存放而非真实存放。修改后提交TL。
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int target = 0, mb; // 目标点 最大背包容量
struct State {
    int node, dis, bag;     // 目标节点 剩余容量 背包数
    State(int n, int d, int bg) : node(n), dis(d), bag(bg) {}
    bool operator<(const State& other) const {
        return bag > other.bag;
    }
};
vector<vector<pair<int,int>>> mp;   // 邻接图
vector<map<int,int>> dp;            // DP背包
void Dijkstra(int n, int start) {
    priority_queue<State> pq;
    pq.push(State(start, mb, 1));   // 错误1:忘记初始化背包容量为满
    dp[start][mb] = 1;
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int u = t.node, ds = t.dis, b = t.bag;
        for (pair<int,int>& p : mp[u]) {
            // 当前路径的重点 权值 新的背包剩余量 背包数
            int v = p.first, w = p.second, nds = 0, bg = b;
            if (ds >= w) {      // 背包容量够
                nds = ds - w;
            } else {            // 换新背包
                nds = mb - w;
                bg++;
            }
            if (!dp[v].count(nds) || bg < dp[v][nds]) {
                dp[v][nds] = bg;
                pq.push(State(v, nds, bg));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int t = INT_MAX;
        if (mp[i].empty()) t = -1;
        else if (i == target) t = 1;
        else {
            for (auto& p : dp[i]) t = min(t, p.second);
            if (t == INT_MAX) t = -1;
        }
        cout<<t<<(i != n ? " " : "");
    }
}
int main(){
    IOS;
    int n, m; cin>>n>>m>>mb>>target;
    mp = vector<vector<pair<int,int>>>(n + 1);
    dp = vector<map<int,int>>(n + 1);
    for (int i = 0 ; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    Dijkstra(n, target);
    return 0;
}
```

> 将原有的距离编码成已用背包量+最新物品重量
即符合真实物品存放（不会一个存一半）
也符合原Dijkstar距离的要求
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll max_bag;
vector<vector<pair<int,int>>> mp;
struct State {
    int node;
    ll weight;  // 物品总价值[编码]
    State(int n, ll w) : node(n), weight(w) {}
    bool operator<(const State& other) const {
        return weight > other.weight;
    } 
};
void Dijkstra(int n, int start) {
    vector<bool> vis(n + 1, false);
    vector<ll> dis(n + 1, LLONG_MAX);
    priority_queue<State> pq;
    pq.push(State(start, 0));
    dis[start] = max_bag;
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int u = t.node; ll w = t.weight;
        if (vis[u]) continue;
        vis[u] = true;

        for (pair<int,int>& p : mp[u]) {
            int v = p.first, w2 = p.second;
            ll bag = w / max_bag, used = w % max_bag;
            if (used + w2 > max_bag) {
                used = w2; bag++;
            } else if (used + w2 == max_bag) {
                used = 0; bag++;
            } else used += w2;
            ll new_weight = bag * max_bag + used; 
            if (dis[v] > new_weight) {
                dis[v] = new_weight;
                pq.push(State(v, dis[v])); 
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ll t = 0;
        if (dis[i] == LLONG_MAX) t = -1;
        else {
            t = dis[i] / max_bag;
            if (dis[i] % max_bag > 0) t++;
        }
        cout<<t<<(i != n ? " " : "");
    }
}
int main() {
    int n, m, start; cin>>n>>m>>max_bag>>start;
    mp = vector<vector<pair<int,int>>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    Dijkstra(n, start);
    return 0;
}
```

# C.**Canvas Painting**

In the Kingdom of Flealand, there is a long canvas divided into n segments, numbered from 1 to n. Each segment is initially painted with a unique color, such that the color of segment i is ai = i.
The royal artist Crysflea has received m magical paint spells. Each spell affects a continuous interval [l, r] on the canvas. When a spell is cast, the artist may choose **any two positions** u and v within this interval (l ≤ u, v ≤ r), and repaint segment u with the color of segment v, i.e., perform au = av. The spells can be used in **any order**, and each spell may be used at most once.
After all spells are used, the artist wishes to admire the canvas. Help the artist **minimize the number of distinct colors** that remain on the canvas.
Input
The input contains multiple test cases.
The first line contains a single integer T (1 ≤ T ≤ 2 × 105) — the number of test cases.
For each test case: - The first line contains two integers m (1 ≤ m ≤ 2 × 105) and n (1 ≤ n ≤ 109) — the number of spells and the length of the canvas. - The next m lines each contain two integers l and r (1 ≤ l ≤ r ≤ n) — describing one paint spell.
The total number of spells across all test cases satisfies Pm ≤ 2 × 105.
Output
For each test case, output a single integer — the minimum number of distinct colors on the canvas after applying the spells.

> 赛时分析：有$n$个不同色的布料，再给你$m$个色块，每个色块可以影响范围是$[l,r]$，每个色块可以使用一次，每个色块使用是从$[l,r]$从选取$u$和$v$，使得$a_u$的颜色变为$a_v$的颜色。问使用若干个色块后，布料的最小不同颜色数量是多少？
> 

> 赛后第一次补题提交，使用并查集，使一个颜色可以尽可能传递到多的区间，可能由于vector容量太大直接RE
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
class UnionFold {
    private:
        ll count;
        vector<ll> parent, size;
    public:
        UnionFold (ll n) : count(n), parent(n + 1), size(n + 1, 1) {
            for (ll i = 1; i <= n; i++)
                parent[i] = i;
        }
        bool merge(ll p, ll q) {
            ll rootP = find(p);
            ll rootQ = find(q);
            if (rootP == rootQ) return false;

            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            count--;
        }
        ll find(ll x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        ll Count() { return count; }
};
int solve() {
    ll n, m; cin>>m>>n;
    UnionFold uf(n);
    for (ll i = 0; i < m; i++) {
        ll a, b; cin>>a>>b;
        uf.merge(a, b);
    }
    return uf.Count();
}
int main() {
    IOS;
    int t; cin>>t;
    while(t--) {
        cout<<solve()<<(t != 0 ? "\n" : "");
    }
    return 0;
}
```

> 题解做法：手动实现区间合并，以左端点分类每个区间，贪心实现每类区间内被消除的布料尽可能多，不同色的数量尽可能少
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int solve() {
    int n, m; cin>>m>>n;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        mp[a].push_back(b);
    }
    vector<pair<int, vector<int>>> adj(mp.begin(), mp.end());
    
    multiset<int> s;
    int res = n;
    for (int i = 0; i < adj.size(); i++) {
        const int& left = adj[i].first;
        vector<int>& right = adj[i].second;

        for (int& t : right) s.insert(t);
        int end = i + 1 == adj.size() ? n : adj[i + 1].first;
        for (int j = left; j < end; j++) {
            while (!s.empty() && *s.begin() <= j) {
                s.erase(s.begin());
            }
            if (s.empty()) break;
            res--;
            s.erase(s.begin());
        }
    }
    return res;
}
int main() {
    IOS;
    int t; cin>>t;
    while(t--) {
        cout<<solve()<<(t != 0 ? "\n" : "");
    }
    return 0;
}
```

# **M. Teleporter**

A country has n cities, with n − 1 roads connecting them. The i-th road connects city ui and vi
, costing w_i units of time to go through the road. Every city is accessible from another city via these roads, forming a tree. Since technology is very developed in the country, there is a teleporter in each city. There are m teleport paths between these teleporters. The i-th path connects the teleporter in city pi and qi. If a person is in city u, he can travel to city v without costing any time if there is a teleport path directly connecting the teleporters in these two cities. As teleporting is very expensive, people can only use the teleporter no more than k times during their trip.
Small N is the minister of transportation of the country. He wants to assess the efficiency of this
transportation network. Precisely speaking, he wants to calculate Pn
u=1 d(u, k) for each k = 0, 1, · · · , n where d(u, k) is the minimum time cost to travel from city u to 1 using teleporters no more than k times.
As the calculation is too complex for him, he wants you to design a program to calculate for him.
Input
The first line contains two integers n and m (1 ≤ n ≤ 5000, 0 ≤ m ≤ 10000), indicating the number of cities and teleport paths.
The following n − 1 lines contain three integers each; the i-th line contains three integers ui, vi and wi (1 ≤ ui, vi ≤ n, 1 ≤ wi ≤ 109), indicating road i connects city ui and vi, costing wi units of time to go through the road.
The following m lines contain two integers each; the i-th line contains two integers pi and qi (1 ≤ pi, qi ≤ n),indicating teleport path i connects the teleporter in city pi and qi.
Output
Your output should contain n+ 1 lines; the i-th line should contain one integer indicating the result when k = i − 1.

> 赛时分析：有n个城市，其中n-1条路，每条路上还有个权值w。同时还有m条传送带，可以使用k次。请你计算从每个点到1的最少权值？请问我的理解对吗？
> 

> 赛时初步规划：建立两层图，一层是城市图，一层用于传送带， 题目是单源最短路径，但是有传送带的存在，不好操作
> 

> 题解思路：使用类Bellman松弛操作更新最短路径。通过建立双向树，保证DP更新所有节点，定义dp[i]为i点到1的最短距离，状态转移为对应点的值小就更新(dp[y] = min(dp[y], dp[x] + w))，最后再松弛更新传送带的距离，k次松弛下得到最终结果。
> 

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const ll INF = 4e18;
void chmin(ll& x, const ll y) {
    if (x > y) x = y;
};
int main() {
    IOS;
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }

    // 双方向的树
    vector<vector<int>> fward, bward;
    //
    function<void(int,int)> dfs = [&](int x, int p) {
        for (pair<int, int>& t : mp[x]) {
            int y = t.first, w = t.second;
            if (y == p) continue;
            fward.push_back({ w, x, y });
            dfs(y, x);
            bward.push_back({ w, y, x });
        }
    };
    dfs(1, -1);

    vector<pair<int, int>> teleporters;
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        teleporters.push_back({u, v});
        teleporters.push_back({v, u});
    }

    // 每个点到1的最短路径
    vector<ll> dp(n + 1, INF);
    dp[1] = 0;
    for (int k = 0; k <= n; k++) {
        // 从叶向根遍历，更新dp
        for (vector<int>& t : bward) {
            int& w = t[0], x = t[1], y = t[2];
            chmin(dp[y], dp[x] + w);
        }
        // 从根向叶遍历，更新dp
        for (vector<int>& t : fward) {
            int& w = t[0], x = t[1], y = t[2];
            chmin(dp[y], dp[x] + w);
        }
        // 双向更新确保所有节点都能被更新
        
        ll sum = 0;
        for (int i = 1; i <= n; i++) if (dp[i] < INF) sum += dp[i];
        cout << sum << "\n";

        auto ndp = dp;
        for (pair<int,int>& p : teleporters) {
            int& x = p.first, y = p.second;
            chmin(ndp[y], dp[x]);
        }
        dp = ndp;
    }
    return 0;
}
```

---

# 赛后反思

1. B题虽然能通过暴力DFS回溯找子集判断最小值来解题，但也只是在小数据量下的侥幸通过
    
    不能害怕去分析公式，要勇敢去拆公式，找到公式的诀窍来解决问题
    
2. G题直接把给与的p[]看作是对每一对进行操作，没有正确理解题目所给的抽象操作
    
    先搞清题目给与的数据是代表什么，不要想太多
    
3. A题主要是对ICPC规则的不熟悉，以及对unknown的判定过于失策
    
    虽然一开始想到了DP，但是DP的关键是要有一个明确的状态转移
    
    使用决策树遍历100%会超时，下次面对这种情况，直接**使用极端情况来简化不确定性问题**
    
4. I题虽然一开始就找到了核心“单源最短路径”，但是搞反了方向
    
    急着就忘了Dijkstar本来就是单源最短路径（一点到所有点），所有点到某一点反而是难点
    
    而且优化要首先考虑状态压缩（如二维压缩成一维），一个信息存两个
    
5. C题我知道了并查集和区间合并，但就是没有去尝试
6. M题知道了是双层图，但不知道n点n-1边就是树，想到了DP，但还是无从下手

---

# 加训

- [ ]  状态压缩Dijkstar
- [ ]  区间合并
- [ ]  部分数学知识