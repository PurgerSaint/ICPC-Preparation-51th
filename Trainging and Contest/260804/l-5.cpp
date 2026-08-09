#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);
    priority_queue<state> pq;
    pq.push({1, 0});
    dis[1] = 0;
    ll sum = 0, mx = 0, cnt = 0;
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (vis[u]) continue;
        if (dis[u] != w) continue;
        vis[u] = 1;
        cnt++;
        sum += w;
        mx = max(mx, w);
        for (auto& [v, w1]: mp[u]) {
            if (!vis[v] && w1 < dis[v]) {
                dis[v] = w1;
                pq.push({v, w1});
            }
        }
    }
    cout << mx;
    return 0;
}
