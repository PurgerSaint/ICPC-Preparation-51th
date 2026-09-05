#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e.emplace_back(u, v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<int> color(n + 1, -1), dep(n + 1, 0), parent(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        dep[i] = 0;
        color[i] = 1;
        parent[i] = i;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v: mp[u]) {
                if (color[v] == -1) {
                    dep[v] = dep[u] + 1;
                    parent[v] = u;
                    color[v] = color[u] == 1 ? 0 : 1;
                    q.push(v);
                }
            }
        }
    }
    int u = -1, v = -1;
    for (auto& [l, r]: e) {
        if (color[l] == color[r]) {
            u = l, v = r;
            break;
        }
    }
    if (u == -1) {
        cout << -1;
        return;
    }

    int x = u, y = v;
    while (dep[x] > dep[y]) x = parent[x];
    while (dep[x] < dep[y]) y = parent[y];
    while (x != y) x = parent[x], y = parent[y];
    int lca = x;

    x = u;
    vector<int> c;
    while (x != lca) {
        c.push_back(x);
        x = parent[x];
    }
    c.push_back(lca);

    vector<int> p;
    y = v;
    while (y != lca) {
        p.push_back(y);
        y = parent[y];
    }
    for (auto it = p.rbegin(); it != p.rend(); it++)
        c.push_back(*it);

    cout << c.size() << "\n";
    for (auto it = c.begin(); it != c.end(); it++)
        cout << *it << (it + 1 != c.end() ? " " : "");
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