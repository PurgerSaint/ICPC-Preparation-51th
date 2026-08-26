#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    ll v, h, w;
    bool operator<(const state& other) const {
        if (other.w != w) return w > other.w;
        return h > other.h;
    }
};

int main() {
    ios;
    int n, m; ll hx; cin >> n >> m >> hx;
    vector<ll> height(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    const ll INF = 1LL << 60;
    vector<vector<ll>> dis(n + 1, vector<ll>(hx + 1, INF));
    priority_queue<state> pq;
    dis[1][0] = 0;
    pq.push({1, 0, dis[1][0]});
    while (!pq.empty()) {
        auto [u, h, w] = pq.top(); pq.pop();
        if (w != dis[u][h] || h > hx) continue;
        for (auto& [v, w1]: mp[u]) {
            ll h1 = 0, nw = w + w1;
            if (height[u] == height[v]) h1 = h;
            else if (height[v] > height[u]) h1 = h + (height[v] - height[u]);
            if (h1 > hx) continue;
            if (nw < dis[v][h1]) {
                dis[v][h1] = nw;
                pq.push({v, h1, nw});
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        ll ans = INF;
        for (int h = 0; h <= hx; h++)
            ans = min(ans, dis[i][h]);
        cout << (ans == INF ? -1 : ans);
        if (i < n) cout << " ";
    }
    return 0;
}