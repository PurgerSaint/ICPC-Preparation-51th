#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, d; cin >> n >> d;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<ll> dis(n + 1, 1LL << 60);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dis[u] + 1 > d) continue;
        for (int& v: mp[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (dis[i] <= d) cnt++;
    cout << cnt;
    return 0;
}