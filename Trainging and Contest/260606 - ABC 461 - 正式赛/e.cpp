#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;

struct bit {
    int n;
    vector<int> tree;
    bit(int n1): n(n1), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

int main() {
    ios;
    int n, q; cin >> n >> q;
    
    vector<int> row_time(n + 1, 0), col_time(n + 1, 0);
    bit bit_row(q + 1), bit_col(q + 1);

    bit_row.add(1, n);
    bit_col.add(1, n);
    ll ans = 0;

    for (int t = 1; t <= q; t++) {
        int k, x; cin >> k >> x;

        if (k == 1) {
            int& last_time = row_time[x];
            ans += n - bit_col.query(last_time);

            bit_row.add(last_time + 1, -1);
            bit_row.add(t + 1, 1);
            last_time = t;
        } else {
            int& last_time = col_time[x];
            ans -= n - bit_row.query(last_time);

            bit_col.add(last_time + 1, -1);
            bit_col.add(t + 1, 1);
            last_time = t;
        }
        cout << ans << (t == q ? "" : "\n");
    }
    
    return 0;
}

/*
# 题目详情：
5. E.cpp E-liter
    有N*N的矩阵，初始都为白色
    有Q个操作：
        第一种为将第R行全刷为黑色
        第二种为将第C列全刷为白色
    每个操作完输出矩阵内黑色格子的数量
*//*
# 提交详情：
- 提交时间:21:05:55 题目:E 状态:TLE 详细状态:AC*22 TLE*33
    用`map<int, set<int>> mat`存储对应状态，为被涂黑的行-被涂白的列
    涂黑若存在，就清空对应set，否则加入新的
    涂白就逐个给set加入对应列
    总和每次都逐个运算
- 提交时间:21:09:27 题目:E 状态:WA 详细状态:AC*15 WA*9 TLE*31
    涂黑简便运算，预留前置变量总和`sum`，存在就是总和减去原有列再清空，不存在就直接加n
    涂白就是每个涂黑行加入对应列，然后再减去所有涂黑行的数量`mat.size()`即可
*/
// 这是我最后的提交代码，你能帮我看看这题我究竟错了哪里吗？