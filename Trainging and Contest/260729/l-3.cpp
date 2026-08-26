#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int node, mask;
    ll dis;
    bool operator<(const state& other) const {
        return dis > other.dis;
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

    const ll INF = (1LL << 60);
    vector<vector<ll>> dis(n + 1, vector<ll>(4, INF));
    dis[1][0] = 0;
    priority_queue<state> pq;
    pq.push({1, 0, 0});
    auto relax = [&](int v, int mask, ll value) {
        if (value < dis[v][mask]) {
            dis[v][mask] = value;
            pq.push({v, mask, value});
        }
    };
    while (!pq.empty()) {
        auto [u, mask, w] = pq.top(); pq.pop();
        if (w != dis[u][mask]) continue;
        for (auto& [v, w1]: mp[u]) {
            relax(v, mask, w + w1);
            if ((mask & 1) == 0) {
                relax(v, mask | 1, w);
            }
            if ((mask & 2) == 0) {
                relax(v, mask | 2, w + 2 * w1);
            }
            if (mask == 0) {
                relax(v, 3, w + w1);
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << (dis[i][3]) << (i < n ? " " : "");
    return 0;
}
