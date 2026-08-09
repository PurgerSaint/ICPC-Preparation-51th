#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int u, v; ll w;
    bool operator<(const state& other) const {
        return w < other.w;
    }
};

struct UnionFold {
    private:
        int count;
        vector<int> parent, size;
    public:
        UnionFold(int n): count(n), parent(n + 1, 1), size(n + 1, 1) {
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
            return true;
        }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<state> p(m);
    ll f_sum = 0;
    for (auto& [u, v, w]: p) {
        cin >> u >> v >> w;
        f_sum += w;
    }
    sort(range(p));
    ll sum = 0, cnt = 0;
    UnionFold b(n);
    for (auto& [u, v, w]: p) {
        if (b.merge(u, v)) {
            sum += w;
            cnt++;
        }
    }
    cout << f_sum - sum;
    return 0;
}
