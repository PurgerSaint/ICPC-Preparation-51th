#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct UnionFold {
    private:
        int count;
        vector<int> parent, size;
    public:
        UnionFold(int n): count(n), parent(n + 1), size(n + 1, 1) {
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
            count--;
            return 1;
        }
};

struct edge {
    int u, v, w;
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<edge> e;
    for (int i = 1; i <= m; i++)
        e.push_back({0, i, n});
    for (int u = 1; u <= m; u++) {
        for (int v = 1; v <= m; v++) {
            int t; cin >> t;
            if (u >= v || t == 0) continue;
            e.push_back({u, v, t});
        }
    }
    UnionFold b(m);
    sort(range(e), [](edge& x, edge& y){
        return x.w < y.w;
    });
    ll sum = 0, cnt = 0;
    for (auto& [u, v, w]: e) {
        if (b.merge(u, v)) {
            sum += w;
            cnt++;
            if (cnt == m) break;
        }
    }
    cout << sum;
    return 0;
}
