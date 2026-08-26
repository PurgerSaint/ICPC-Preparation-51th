#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const ll INF = 1LL << 60;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if ((int)mp[i].size() < 2) continue;
        vector<ll> dis(n + 1, INF);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v: mp[u]) {
                if (dis[v] != INF && dis[u] > dis[v] && (dis[v] - dis[u]) % 2) {
                    vector<int> path;
                    path.push_back(v);
                    int node = v;
                    while (parent[node] != -1) {
                        path.push_back(node);
                        if (node == u) break;
                        node = parent[node];
                    }
                    int sz = path.size();
                    cout << u << " " << v << " " << sz << "\n";
                    if (path.back() == u && sz % 2) {
                        cout << sz << "\n";
                        for (int i = 0; i < sz; i++)
                            cout << path[i] << (i < sz - 1 ? " " : "");
                        return;
                    }
                }
                if (dis[u] + 1 < dis[v]) {
                    parent[v] = u;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}