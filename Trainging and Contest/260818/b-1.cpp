#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int v;
    ll bag, w;
    bool operator<(const state& other) const {
        if (other.bag != bag) return bag > other.bag;
        return w > other.w;
    }
};

int main() {
    ios;
    int n, m, T; ll V; cin >> n >> m >> V >> T;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    const ll INF = 1LL << 60;
    vector<ll> bag(n + 1, INF), dis(n + 1, INF);
    priority_queue<state> pq;
    pq.push({T, 1, 0});
    dis[T] = 0;
    bag[T] = 1;
    while (!pq.empty()) {
        auto [u, b, w] = pq.top(); pq.pop();
        if (w != dis[u] || b != bag[u]) continue;
        for (auto& [v, w1]: mp[u]) {
            ll nw = w + w1, nb = b;
            if (w + w1 > V) {
                nw = w1;
                nb = b + 1;
            }
            if (nb < bag[v] || (nb == bag[v] && nw < dis[v])) {
                bag[v] = nb;
                dis[v] = nw;
                pq.push({v, nb, nw});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) cout << -1;
        else cout << bag[i];
        if (i < n) cout << " ";
    }
    return 0;
}