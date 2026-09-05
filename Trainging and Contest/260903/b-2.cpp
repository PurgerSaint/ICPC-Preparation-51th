#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

void solve() {
    int n, m, q, s, t; cin >> n >> m >> q >> s >> t;
    vector<vector<int>> mp(n + 1);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
        e.emplace_back(u, v);
    }
    vector<int> color(n + 1, -1);
    color[s] = 0;
    color[t] = 1;
    queue<int> p;
    p.push(s);
    p.push(t);
    while (!p.empty()) {
        int u = p.front(); p.pop();
        for (int& v: mp[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                p.push(v);
            }
        }
    }
    bool f = 0;
    for (auto& [u, v]: e) {
        if (color[u] == color[v]) {
            f = 1;
            break;
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        if (f || (color[u] == color[s] && color[v] == color[t])) cout << "Yes";
        else cout << "No";
        if (q) cout << "\n";
    }
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