#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int node; ll bag, w;
    bool operator<(const state& other) const {
        if (bag != other.bag) return bag > other.bag;
        return w > other.w;
    } 
};

int main() {
    ios;
    const ll INF = 1LL << 60;
    int n, m, t; ll x; cin >> n >> m >> x >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    vector<ll> dis(n + 1, INF);
    vector<ll> bag(n + 1, INF);
    priority_queue<state> pq;
    pq.push({t, 1, 0});
    dis[t] = 0;
    bag[t] = 1;
    while (!pq.empty()) {
        auto [u, b, w] = pq.top(); pq.pop();
        if (dis[u] != w || bag[u] != b) continue;
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
                dis[v] = nw;
                bag[v] = nb;
                pq.push({v, nb, nw});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (bag[i] == INF) cout << -1;
        else cout << bag[i];
        if (i < n) cout << " ";
    }
    return 0;
}
