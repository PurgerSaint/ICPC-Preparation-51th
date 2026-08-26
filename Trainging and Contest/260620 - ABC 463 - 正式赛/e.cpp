#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
struct state {
    int node;
    ll dis;
    state(int n, ll d): node(n), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};
int main() {
    ios;
    int n, m; ll y; cin >> n >> m >> y;
    vector<vector<pair<int,ll>>> mp(n + 2);
    for (int i = 0; i < m; i++) {
        int u, v; ll t; cin >> u >> v >> t;
        mp[u].push_back({v, t});
        mp[v].push_back({u, t});
    }
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        mp[i].push_back({n + 1, x[i] + y});
        mp[n + 1].push_back({i, x[i]});
    }

    vector<ll> dis(n + 2, LLONG_MAX);
    dis[1] = 0;
    priority_queue<state> pq;
    pq.push(state(1, 0));
    while (!pq.empty()) {
        state t = pq.top(); pq.pop();
        int& u = t.node;
        ll& w = t.dis;
        if (w > dis[u]) continue;

        for (pair<int, ll>& p: mp[u]) {
            int& v = p.first;
            ll& w2 = p.second;
            if (dis[u] + w2 < dis[v]) {
                dis[v] = dis[u] + w2;
                pq.push(state(v, dis[v]));
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << dis[i] << (i < n ? " " : "");
    return 0;
}