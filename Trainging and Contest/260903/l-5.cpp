#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
        mp[v].emplace_back(u, w);
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    dis[s] = 0;
    priority_queue<state> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (auto& [v, w1]: mp[u]) {
            if (max(w, w1) < dis[v]) {
                dis[v] = max(w, w1);
                pq.push({v, dis[v]});
            }
        }
    }
    cout << dis[t];
    return 0;
}