#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int u, k; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m, K; cin >> n >> m >> K;
    int s, t; cin >> s >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    const ll INF = 1LL << 60;
    vector<vector<ll>> dis(n + 1, vector<ll>(K + 1, INF));
    priority_queue<state> pq;
    dis[s][0] = 0;
    pq.push({s, 0, 0});
    while (!pq.empty()) {
        auto [u, k, w] = pq.top(); pq.pop();
        if (w != dis[u][k]) continue;
        for (auto& [v, w1]: mp[u]) {
            if (k < K && w < dis[v][k + 1]) {
                dis[v][k + 1] = w;
                pq.push({v, k + 1, w});
            }
            if (w + w1 < dis[v][k]) {
                dis[v][k] = w + w1;
                pq.push({v, k, w + w1});
            }
        }
    }
    cout << *min_element(range(dis[t]));
    return 0;
}