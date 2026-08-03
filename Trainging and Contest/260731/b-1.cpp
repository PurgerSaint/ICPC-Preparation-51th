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
    int n, m, s;
    while (cin >> n >> m >> s) {
        vector<vector<pair<int, ll>>> mp(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v; ll w; cin >> u >> v >> w;
            mp[v].push_back({u, w});
        }
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
        ll mn = INF;
        int k; cin >> k;
        while (k--) {
            int t; cin >> t;
            mn = min(mn, dis[t]);
        }
        cout << (mn == INF ? -1 : mn) << "\n";
    }
    return 0;
}
