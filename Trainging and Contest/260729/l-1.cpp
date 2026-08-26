#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int node, cnt;
    ll cost;
    state(int n, int f, ll c): node(n), cnt(f), cost(c) {}
    bool operator<(const state& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios;
    int n, m, k; cin >> n >> m >> k;
    int s, t; cin >> s >> t;
    vector<vector<pair<int, ll>>> mp(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll c; cin >> u >> v >> c;
        mp[u].push_back({v, c});
        mp[v].push_back({u, c});
    }
    const ll INF = 4e18;
    vector<vector<ll>> dis(n, vector<ll>(k + 1, INF));
    priority_queue<state> pq;
    pq.push({s, 0, 0});
    dis[s][0] = 0;

    while (!pq.empty()) {
        auto [u, cnt, cost] = pq.top(); pq.pop();
        if (cost != dis[u][cnt]) continue;
        for (auto& [v, price]: mp[u]) {
            if (cost + price < dis[v][cnt]) {
                dis[v][cnt] = cost + price;
                pq.push({v, cnt, dis[v][cnt]});
            }
            if (cnt < k && cost < dis[v][cnt + 1]) {
                dis[v][cnt + 1] = cost;
                pq.push({v, cnt + 1, cost});
            }
        }
    }
    ll ans = INF;
    for (int cnt = 0; cnt <= k; cnt++)
        ans = min(ans, dis[t][cnt]);
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}
