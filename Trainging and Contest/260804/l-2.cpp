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
        UnionFold(int n): count(n), parent(n + 1, 0), size(n + 1, 1) {
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        bool merge(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return false;
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            count--;
            return true;
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
};

struct state {
    int u, v; ll w;
    bool operator<(const state& other) const {
        return w < other.w;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<state> edge;
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(range(edge));
    ll sum = 0, cnt = 0;
    UnionFold b(n);
    for (auto& [u, v, w]: edge) {
        if (b.merge(u, v)) {
            sum += w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    if (cnt < n - 1) cout << "orz";
    else cout << sum;
    return 0;
}
