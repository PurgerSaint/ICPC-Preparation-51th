#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int node;
    ll dis;
    state(int n, ll d): node(n), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

vector<ll> Dijkstra(vector<vector<pair<int, ll>>>& mp, int& n, int s) {
    vector<ll> dis(n + 1, INF);
    priority_queue<state> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (w != dis[u]) continue;
        for (auto& [v, w1]: mp[u]) {
            if (w + w1 < dis[v]) {
                dis[v] = w + w1;
                pq.push({v, dis[v]});
            }
        }
    }
    return dis;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp1(n + 1), mp2(n + 1);
    vector<tuple<int, int, ll>> p(m + 1);
    for (int i = 1; i <= m; i++) {
        auto& [u, v, w] = p[i];
        cin >> u >> v >> w;
        mp1[u].push_back({v, w});
        mp2[v].push_back({u, w});
    }

    vector<ll> dis1 = Dijkstra(mp1, n, 1), dis2 = Dijkstra(mp2, n, 2);
    vector<vector<pair<int, int>>> dag(n + 1);
    vector<bool> on_shortest(m + 1, false);
    for (int i = 1; i <= m; i++) {
        auto& [u, v, w] = p[i];
        if (dis1[u] != INF && dis2[v] != INF && dis1[u] + w + dis2[v] == dis1[2]) {
            on_shortest[i] = 1;
            dag[u].push_back({v, i});
        }
    }

    for (int i = 1; i <= m; i++) {
        auto& [u, v, w] = p[i];
        ll nw = 0;
        if (dis1[v] == INF || dis2[u] == INF) nw = INF;
        else nw = dis1[v] + w + dis2[u];
        if (nw < dis1[2]) cout << "HAPPY";
        else if (nw == dis1[2]) cout << "SOSO";
        else {
            if (on_shortest[i]) {
                
            } else cout << "SOSO";
        }
        if (i < m) cout << "\n";
    }
    return 0;
}
