#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<int>> mp, f;
vector<int> dep, cnt;
string s;
const int LOGN = 20;
void dfs(int u, int fa, int d, int t) {
    f[u][0] = fa;
    dep[u] = d;
    cnt[u] = t + (s[u] == 'H');
    for (int i = 1; i < LOGN; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int& v: mp[u]) {
        if (v != fa) {
            dfs(v, u, d + 1, cnt[u]);
        }
    }
}

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
    int n, m; cin >> n >> m;
    mp = vector<vector<int>>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(LOGN));
    dep = cnt = vector<int>(n + 1, 0);
    cin >> s;
    s = ' ' + s;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs(1, 1, 1, 0);
    while (m--) {
        int u, v; char c; cin >> u >> v >> c;

        int lca = getLCA(u, v);
        int ct = cnt[u] + cnt[v] - 2 * cnt[lca] + (s[lca] == 'H');
        int node_num = dep[u] + dep[v] - 2 * dep[lca] + 1;
        if (c == 'H') cout << (ct ? "1" : "0");
        else cout << (node_num - ct ? "1" : "0");
    }
    return 0;
}