#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

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
        int cnt() { return count; }
};
struct state {
    int u, v, w;
};

int main() {
    ios;
    int a, b; cin >> a >> b;
    UnionFold f(b);
    vector<state> g;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            int t; cin >> t;
            if (i >= j || t == 0) continue;
            g.push_back({i, j, t});
        }
    }
    sort(range(g), [](state& x, state& y){
        return x.w < y.w;
    });
    ll ans = 0;
    for (auto& [u, v, w]: g) {
        // cout << "edge:" << u << " " << v << " " << w << "\n";
        if (a >= w && f.merge(u, v)) {
            // cout << u << " to: " << v << " " << w << "\n";
            ans += w;
        }
    }
    cout << ans + a * f.cnt();
    return 0;
}