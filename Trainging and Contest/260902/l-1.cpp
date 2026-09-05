#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        in[v]++;
    }

    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int& v: mp[u]) {
            dp[v] = max(dp[v], 1 + dp[u]);
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dp[i] << (i < n ? "\n" : "");
    return 0;
}