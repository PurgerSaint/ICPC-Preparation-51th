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

vector<ll> Dijkstra(vector<vector<pair<int, ll>>>& mp, const int& n, int s) {
    vector<ll> dis(n + 1, INF);
    priority_queue<state> pq;
    dis[s] = 0;
    pq.push({s, dis[s]});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (auto& [v, w1]: mp[u]) {
            if (w + w1 < dis[v]) {
                dis[v] = w + w1;
                pq.push({v, w + w1});
            }
        }
    }
    return dis;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp1(n + 1), mp2(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp1[u].push_back({v, w});
        mp2[v].push_back({u, w});
    }
    vector<ll> dis1 = Dijkstra(mp1, n, 1), dis2 = Dijkstra(mp2, n, 1);
    ll sum = 0;
    for (int i = 2; i <= n; i++)
        if (dis1[i] != INF && dis2[i] != INF) sum += dis1[i] + dis2[i];
    cout << sum;
    return 0;
}
