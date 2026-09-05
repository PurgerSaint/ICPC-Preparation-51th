#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int node, k; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m, mx; cin >> n >> m >> mx;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
        mp[v].emplace_back(u, w);
    }
    const ll INF = 1LL << 60;
    vector<vector<ll>> dis(n + 1, vector<ll>(mx + 1, INF));
    priority_queue<state> pq;
    dis[1][0] = 0;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        auto [u, k, w] = pq.top(); pq.pop();
        if (dis[u][k] != w) continue;
        for (auto& [v, w1]: mp[u]) {
            if (k + 1 <= mx && w < dis[v][k + 1]) {
                dis[v][k + 1] = w;
                pq.push({v, k + 1, w});
            }
            if (max(w, w1) < dis[v][k]) {
                dis[v][k] = max(w, w1);
                pq.push({v, k, max(w, w1)});
            }
        }
    }
    ll ans = *min_element(range(dis[n]));
    cout << (ans == INF ? -1 : ans);
    return 0;
}