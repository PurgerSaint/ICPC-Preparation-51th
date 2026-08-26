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