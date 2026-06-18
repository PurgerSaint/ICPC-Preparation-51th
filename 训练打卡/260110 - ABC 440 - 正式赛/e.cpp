// e.cpp
/*
    给与N种不同味道的饼干，每种饼干数量为1e100（等价于无限）
    要求组合K种饼干（可以重复选），按降序输出前X个组合的味道总和
    1 <= N <= 50
    1 <= k <= 1e5
    1 <= x <= min(1e5, C_{N + K - 1, K})
    -1e9 <= a_i <= 1e9
*/
#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

struct State {
    ll sum;
    vector<int> cnt;
    bool operator<(const State& other) const {
        return sum < other.sum;
    }
};

int main() {
    ios;
    int n, k, x; cin >> n >> k >> x;
    vector<ll> c(n);
    for (ll& t: c) cin >> t;
    sort(c.begin(), c.end(), [](ll& a, ll& b) { return a > b; });

    priority_queue<State> pq;

    set<vector<int>> vis;       // 每一种饼干组合方式
    vector<int> init(n, 0);     // 饼干组合方式
    init[0] = k;
    ll init_sum = (ll)k * c[0];

    pq.push({init_sum, init});
    vis.insert(init);

    while (!pq.empty() && x > 0) {
        State p = pq.top(); pq.pop();
        cout << p.sum << (x != 1 ? "\n" : "");
        x--;
        if (x == 0) break;

        for (int i = 0; i < n - 1; i++) {
            if (p.cnt[i] > 0) {
                vector<int> next = p.cnt;
                next[i]--;
                next[i + 1]++;

                if (!vis.count(next)) {
                    vis.insert(next);
                    ll next_sum = p.sum - c[i] + c[i + 1];
                    pq.push({next_sum, next});
                }
            }
        }
    }
    return 0;
}

// 第一次想法，暴力枚举每一种情况，使用多层循环（不可能实现）
//  // 不使用DFS：DFS不好判断何时退出，主要是我不太会使用DFS，容易多重递归
//  // 显而易见地容易超时
//  // 不使用DP：无法拆解状态
// 第二次AI帮助下：可重复数的Top-K问题
//  // 最大和永远是那个最大值*k，因为多点降级和跨级降级的竞争下，可能存在后者总和大于前者的情况，故不能固定输出
//  // 也是树形扩展问题，最大的父节点总是最大*k，然后逐个替换为次大，直到全部被替换完，然后到次次大
//  // 所以本题是BFS优先队列 + 贪心(从最大开始)
