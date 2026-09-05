#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<int>> mp, f;
vector<int> dep;
const int LOGN = 20;

void dfs(int u, int fa, int d) {
    dep[u] = d;
    f[u][0] = fa;
    for (int i = 1; i < LOGN; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int& v: mp[u]) {
        if (v != fa)
            dfs(v, u, d + 1);
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
    int n, m, s; cin >> n >> m >> s;
    mp = vector<vector<int>>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(LOGN));
    dep = vector<int>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dep[s] = 1;
    f[s][0] = s;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
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
    while (m--) {
        int u, v; cin >> u >> v;
        cout << getLCA(u, v) << (m ? "\n" : "");
    }
    return 0;
}