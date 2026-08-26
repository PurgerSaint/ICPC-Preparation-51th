#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int node; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

string solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    vector<int> parent(n + 1, -1);
    queue<int> pq;
    pq.push(1);
    dis[1] = 0;
    parent[1] = 1;
    while (!pq.empty()) {
        int u = pq.front(); pq.pop();
        for (auto& [v, w1]: mp[u]) {
            if (v == parent[u]) continue;
            if (dis[v] == INF) {
                parent[v] = u;
                dis[v] = dis[u] + w1;
                pq.push(v);
            } else if (dis[u] + w1 < 0) return "YES";
        }
    }
    return "NO";
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}