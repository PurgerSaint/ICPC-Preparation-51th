#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int node; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

const ll INF = 1LL << 60;
vector<ll> Dijkstra(int s, int n, vector<vector<pair<int, ll>>>& mp) {
    vector<ll> dis(n + 1, INF);
    priority_queue<state> pq;
    pq.push({s, 0});
    dis[s] = 0;
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
    vector<int> p(m);
    for (int& t: p) cin >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            ll t; cin >> t;
            if (u == v) continue;
            mp[u].push_back({v, t});
            // mp[v].push_back({u, t});
        }
    }
    vector<vector<ll>> dis(n + 1);
    for (int i = 1; i <= n; i++) {
        dis[i] = Dijkstra(i, n, mp); 
    }
    ll ans = 0;
    for (auto it = p.begin(); it + 1 != p.end(); it++) {
        int u = *it, v = *(it + 1);
        ans += dis[u][v];
    }
    cout << ans;
    return 0;
}
