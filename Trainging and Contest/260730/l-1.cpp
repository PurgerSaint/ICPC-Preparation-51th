#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

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
    int n, m, s;
    while (cin >> n >> m >> s) {
        vector<vector<pair<int, ll>>> mp(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v; ll w; cin >> u >> v >> w;
            mp[v].push_back({u, w});
        }
        int t; cin >> t;
        vector<int> sta(t);
        for (int& g: sta) cin >> g;
        const ll INF = 1LL << 60;
        vector<ll> dis(n + 1, INF);
        priority_queue<state> pq;
        pq.push({s, 0});
        dis[s] = 0;
        while (!pq.empty()) {
            state g = pq.top(); pq.pop();
            int& u = g.node; ll& w = g.dis;
            if (dis[u] != w) continue;
            for (pair<int, ll>& p: mp[u]) {
                int& v = p.first; ll& w1 = p.second;
                if (w + w1 < dis[v]) {
                    dis[v] = w + w1;
                    pq.push({v, w + w1});
                }
            }
        }
        ll mn = INF;
        for (int& i: sta) mn = min(mn, dis[i]);
        cout << (mn == INF ? -1 : mn) << "\n";
    }
    return 0;
}