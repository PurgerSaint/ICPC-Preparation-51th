#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int k, n, m; cin >> k >> n >> m;
    vector<int> cow(k);
    for (int& c: cow) cin >> c;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
    }
    vector<int> cnt(n + 1, 0);
    for (int& c: cow) {
        vector<bool> f(n + 1, 0);
        queue<int> q;
        q.push(c);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (f[u]) continue;
            cnt[u]++;
            f[u] = 1;
            for (int& v: mp[u]) {
                if (!f[v]) q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (cnt[i] == k);
    cout << ans;
    return 0;
}