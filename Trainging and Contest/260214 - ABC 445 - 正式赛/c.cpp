#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

class UnionFold {
    public:
        int count;
        vector<int> parent;

        UnionFold(int n): count(n), parent(n + 1) {
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        void unionSet(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) return;
            parent[rootP] = rootQ;
            count--;
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        vector<int> res() {
            return parent;
        }
};

int main() {
    ios;
    int n; cin >> n;
    UnionFold f(n);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        f.unionSet(i, t);
    }
    for (int i = 1; i <= n; i++) {
        cout << f.find(i) << (i != n ? " " : "");
    }
    return 0;
}