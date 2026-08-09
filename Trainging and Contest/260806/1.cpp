#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct UnionFold {
    int count;
    vector<int> parent, size;
    UnionFold(int n): count(n), parent(n + 1, 0), size(n + 1, 1) {
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
        if (rootP > rootQ) {
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

int main() {
    ios;
    int n; cin >> n;
    UnionFold b(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--)
        b.merge(i, a[i]);
    for (int i = 1; i <= n; i++)
        cout << b.parent[i] << (i < n ? " " : "");
    return 0;
}
