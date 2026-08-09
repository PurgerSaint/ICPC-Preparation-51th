#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct UnionSet {
    private:
        int count;
        vector<int> parent, size;
    public:
        UnionSet(int n): count(n), parent(n + 1, 1), size(n + 1, 1) {
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        void merge(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return;
            if (size[rootP] > size[rootQ]) {
                size[rootP] += size[rootQ];
                parent[rootQ] = rootP;
            } else {
                size[rootQ] += size[rootP];
                parent[rootP] = rootQ;
            }
            count--;
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
};

int main() {
    ios;
    int n, m, q; cin >> n >> m >> q;
    UnionSet b(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        b.merge(x, y);
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if (b.find(x) == b.find(y)) cout << "Yes";
        else cout << "No";
        if (q) cout << "\n";
    }
    return 0;
}
