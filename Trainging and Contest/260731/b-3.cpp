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

int main() {
    ios;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    vector<ll> dis(n + 1, INF);
    vector<bool> open(n + 1, 0);
    priority_queue<state> pq;
    pq.push({1, 0});
    dis[1] = 0;
    for (int i = 0; i < k; i++) {
        int s; ll y; cin >> s >> y;
        if (y < dis[s]) {
            open[s] = 1;
            dis[s] = y;
            pq.push({s, y});
        }
    }
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (auto& [v, w1]: mp[u]) {
            if (w + w1 < dis[v]) {
                open[v] = 0;
                dis[v] = w + w1;
                pq.push({v, w + w1});
            } else if (open[v] && w + w1 == dis[v]) {
                open[v] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (open[i]) cnt++;
    }
    cout << (k - cnt);
    return 0;
}
