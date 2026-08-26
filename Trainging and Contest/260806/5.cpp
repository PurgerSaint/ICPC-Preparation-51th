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

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp(n + 1);
    ll s = 0;
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        if (w == 0) continue;
        s += w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    ll sum = 0;
    priority_queue<state> pq;
    vector<bool> vis(n + 1, 0);
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        sum += w;
        for (auto& [v, w1]: mp[u]) {
            if (!vis[v]) {
                pq.push({v, w1});
            }
        }
    }
    cout << s - sum;
    return 0;
}
