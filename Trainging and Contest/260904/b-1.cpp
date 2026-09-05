#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

void solve() {
    int n, m, k, s, t; cin >> n >> m >> k >> s >> t;
    vector<vector<int>> mp(n + 1);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
        e.emplace_back(u, v);
    }
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v: mp[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v); 
                }
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

    while (k--) {
        int u, v; cin >> u >> v;
        if (f || (color[s] == color[u] && color[t] == color[v])) cout << "Yes";
        else cout << "No";
        if (k) cout << "\n";
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