#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    const ll MOD = 100003;
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    dis[1] = 0;
    priority_queue<state> pq;
    pq.push({1, dis[1]});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (w != dis[u]) continue;
        for (int& v: mp[u]) {
            if (w + 1 < dis[v]) {
                dis[v] = w + 1;
                pq.push({v, dis[v]});
            }
        }
    }
    vector<int> d(n + 1);
    for (int i = 0; i <= n; i++)
        d[i] = i;
    sort(range(d), [&](int& x, int& y) {
        return dis[x] < dis[y];
    });
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    // cout << dis[5] << "\n";
    for (int& v: d) {
        ll& w = dis[v];
        if (!w || w == INF) continue;
        for (int& u: mp[v]) {
            // cout << v << " " << w << " " << u << " " << dis[u] << "\n";
            if (dis[u] + 1 == w) {
                dp[v] = mod(dp[v] + dp[u], MOD);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i] << (i < n ? "\n" : "");
    return 0;
}