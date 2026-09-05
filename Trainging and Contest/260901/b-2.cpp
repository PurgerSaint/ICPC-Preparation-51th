#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<int>> mp, f;
vector<int> dep;
const int LOGN = 20;

int getLCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

int main() {
    ios;
    int n, k; cin >> n >> k;
    dep = vector<int>(n + 1);
    mp = vector<vector<int>>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(LOGN));
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dep[1] = 1;
    f[1][0] = 1;
    queue<int> q;
    vector<int> path;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        path.push_back(u);
        for (int i = 1; i < LOGN; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for (int& v: mp[u]) {
            if (v != f[u][0]) {
                dep[v] = dep[u] + 1;
                f[v][0] = u;
                q.push(v);
            }
        }
    }
    vector<int> diff(n + 1);
    while (k--) {
        int u, v; cin >> u >> v;
        diff[u]++;
        diff[v]++;
        int l = getLCA(u, v);
        diff[l]--;
        if (f[l][0] != 0)
            diff[f[l][0]]--;
    }
    int ans = 0;
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        int& u = *it;
        ans = max(ans, diff[u]);
        if (f[u][0] != 0)
            diff[f[u][0]] += diff[u];
    }
    cout << ans;
    return 0;
}