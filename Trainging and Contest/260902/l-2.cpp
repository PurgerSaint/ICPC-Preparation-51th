#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    const int x = 505;
    vector<vector<int>> mp(x);
    vector<int> in(x);
    int mx = 0;
    vector<bool> vis(x, 0);
    for (int i = 1; i <= n; i++) {
        int u, c; cin >> u >> c;
        vis[u] = 1;
        mx = max(mx, u);
        for (int i = 0; i < c; i++) {
            int v; cin >> v;
            mp[u].push_back(v);
            in[v]++;
            mx = max(mx, v);
        }
    }

    queue<int> q;
    for (int i = 1; i <= mx; i++)
        if (!in[i]) q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vis[u]) cnt++;
        for (int& v: mp[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }

    if (n == cnt) cout << "YES";
    else cout << (n - cnt);
    return 0;
}
