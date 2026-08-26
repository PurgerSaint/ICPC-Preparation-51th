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
        bool merge(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return false;
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
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        int cnt() { return count; }
};

struct road {
    int x, y;
    int time;
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    UnionSet b(n);
    vector<road> p(m);
    for (auto& [x, y, t]: p)
        cin >> x >> y >> t;
    sort(range(p), [](road& i, road& j){
        return i.time < j.time;
    });
    int time = 0;
    for (auto& [x, y, t]: p) {
        if (b.merge(x, y))
            time = max(time, t);
    }
    if (b.cnt() > 1) cout << -1;
    else cout << time;
    return 0;
}
