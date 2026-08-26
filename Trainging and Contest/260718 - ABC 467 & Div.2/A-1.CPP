#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

class UnionFold {
    private:
        int count;
        vector<int> parent;
        vector<int> size; 
    public:
        UnionFold(int n) : count(n), parent(n), size(n, 1) {
            for (int i = 0; i < n; i++) {
                parent[i]=i;
            }
        }
        void unionSets(int p, int q){
            int rootP = find(p);int rootQ = find(q);
            if (rootP == rootQ) return;
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP; size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ; size[rootQ] += size[rootP];
            }
            count--;
        }
        bool connected(int p, int q) { return find(q) == find(p); }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        int Count() { return count; }
};

int main() {
    ios;
    /*
    int n, m;
    while (cin >> n && n != 0) {
        cin >> m;
        UnionFold b(n);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            b.unionSets(u - 1, v - 1);
        }
        int c = b.Count();
        if (c == 1) cout << 0;
        else cout << c - 1;
        cout << "\n";
    }*/
    cout << (0 % 2);
    return 0;
}