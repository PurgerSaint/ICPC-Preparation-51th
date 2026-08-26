#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
const ll INF = (1LL << 60);

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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    vector<ll> dis(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<state> pq;

    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        auto [u, w] = pq.top();
        pq.pop();
        if (dis[u] != w) continue;
        if (u == n) break;
        for (auto& [v, w2]: mp[u]) {
            if (dis[v] > w + w2) {
                dis[v] = w + w2;
                parent[v] = u;
                pq.push({v, dis[v]});
            }
        }
    }

    if (dis[n] == INF) {
        cout << -1;
    } else {
        vector<int> ans;
        int node = n;
        while (node != -1) {
            ans.push_back(node);
            if (node == 1) break;
            node = parent[node];
        }
        for (auto it = ans.rbegin(); it != ans.rend(); it++)
            cout << *it << (it + 1 != ans.rend() ? " " : "");
    }
    return 0;
}
