#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int node, cnt; ll dis;
    state(int n, int c, ll d): node(n), cnt(c), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

int main() {
    ios;
    int n, m, k; cin >> n >> m >> k;
    int s, t; cin >> s >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }

    const ll INF = 1LL << 60;
    vector<vector<ll>> dis(n + 1, vector<ll>(k + 1, INF));
    priority_queue<state> pq;
    pq.push({s, 0, 0});
    dis[s][0] = 0;
    while (!pq.empty()) {
        auto [u, cnt, w] = pq.top(); pq.pop();
        if (w != dis[u][cnt]) continue;
        if (u == t) break;
        for (auto& [v, w1]: mp[u]) {
            if (w + w1 < dis[v][cnt]) {
                dis[v][cnt] = w + w1;
                pq.push({v, cnt, w + w1});
            }
            if (cnt + 1 <= k && w < dis[v][cnt + 1]) {
                dis[v][cnt + 1] = w;
                pq.push({v, cnt + 1, w});
            }
        }
    }
    ll mn = INF;
    for (ll& g: dis[t]) mn = min(mn, g);
    cout << mn;
    return 0;
}
