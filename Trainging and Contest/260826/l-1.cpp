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

bool find() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int l1 = getLCA(x1, y1), l2 = getLCA(x2, y2);
    if (l1 == l2) return 1;
    if (dep[l1] == dep[l2]) return 0;
    
    int x = x1, y = y1, l = l1, lt = l2;
    auto dist = [&](int u, int v) -> int {
        return dep[u] + dep[v] - 2 * dep[getLCA(u, v)];
    };
    if (dep[l1] < dep[l2])
        return dist(x1, l2) + dist(l2, y1) == dist(x1, y1);
    return dist(x2, l1) + dist(l1, y2) == dist(x2, y2);
}

int main() {
    ios;
    int n, k; cin >> n >> k;
    mp = vector<vector<int>>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(LOGN));
    dep = vector<int>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    f[1][0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i < LOGN; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for (int& v: mp[u]) {
            if (v != f[u][0]) {
                f[v][0] = u;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    while (k--) {
        cout << (find() ? "Y" : "N") << (k ? "\n" : "");
    }
    return 0;
}