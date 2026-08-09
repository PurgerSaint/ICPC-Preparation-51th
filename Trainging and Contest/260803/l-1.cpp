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
            for (int i = 1; i <= n; i++)
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
        bool connect(int p, int q) {
            return find(p) == find(q);
        }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    UnionFold b(n);
    while (m--) {
        int z, x, y; cin >> z >> x >> y;
        if (z == 1) b.merge(x, y);
        else cout << (b.connect(x, y) ? "Y" : "N") << (m ? "\n" : "");
    }
    return 0;
}
