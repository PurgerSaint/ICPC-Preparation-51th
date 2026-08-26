#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct UnionFold {
    int cnt;
    vector<int> parent, size;
    UnionFold(int n): cnt(n), parent(n + 1), size(n + 1, 1) {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ) return 0;
        if (size[rootP] > size[rootQ]) {
            size[rootP] += size[rootQ];
            parent[rootQ] = rootP;
        } else {
            size[rootQ] += size[rootP];
            parent[rootP] = rootQ;
        }
        return 1;
    }
};

int main() {
    ios;
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = ' ' + s;
    vector<pair<int, int>> e(n - 1);
    UnionFold h(n), g(n);
    for (auto& [u, v]: e) {
        cin >> u >> v;
        if (s[u] == s[v]) {
            if (s[u] == 'H') h.merge(u, v);
            else g.merge(u, v);
        }
    }
    while (q--) {
        int u, v; char c; cin >> u >> v >> c;
        if (c == 'H') cout << (s[u] == 'H' || s[v] == 'H' || g.find(u) != g.find(v));
        else cout << (s[u] == 'G' || s[v] == 'G' || h.find(u) != h.find(v));
    }
    return 0;
}