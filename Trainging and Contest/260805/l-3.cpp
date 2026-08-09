#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> mp(n + 1);
    vector<int> time(n + 1, 0);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int u, t; cin >> u >> t;
        time[u] = t;
        while (1) {
            int v; cin >> v;
            if (!v) break;
            mp[v].push_back(u);
            in[u]++;
        }
    }
    queue<int> q;
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
            dp[i] = time[i];
        }
    } 
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int& v: mp[u]) {
            dp[v] = max(dp[v], dp[u] + time[v]); 
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    cout << *max_element(range(dp));
    return 0;
}