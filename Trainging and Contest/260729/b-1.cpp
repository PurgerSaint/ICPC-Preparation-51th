#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
struct state {
    int node;
    ll bag, load;
    state(int n, ll b, ll l): node(n), bag(b), load(l) {}
    bool operator<(const state& other) const {
        if (bag != other.bag) return bag > other.bag;
        return load > other.load;
    }
};

int main() {
    ios;
    int n, m, x, t; cin >> n >> m >> x >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }

    const ll INF = 4e18;
    vector<ll> bag(n + 1, INF), dis(n + 1, INF);
    priority_queue<state> pq;
    pq.push({t, 0, 0});
    bag[t] = 0;
    dis[t] = 0;
    while (!pq.empty()) {
        auto [u, b, w] = pq.top(); pq.pop();
        if (w != dis[u] || b != bag[u]) continue;
        for (auto& [v, w1]: mp[u]) {
            ll nb = 0, nw = 0;
            if (w + w1 > x) {
                nb = b + 1;
                nw = w1;
            } else {
                nb = b;
                nw = w + w1;
            }

            if (nb < bag[v] || (nb == bag[v] && nw < dis[v])) {
                bag[v] = nb, dis[v] = nw;
                pq.push({v, nb, nw});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == t) cout << 1;
        else if (bag[i] == INF) cout << -1;
        else cout << bag[i] + 1;
        if (i < n) cout << " ";
    }
    return 0;
}