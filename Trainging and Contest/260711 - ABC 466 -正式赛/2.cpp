#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

struct bit {
    int n;
    vector<ll> tree;
    bit(int n1): n(n1), tree(n + 2, 0) {}
    void add(int i, ll delta) {
        if (i <= 0) return;
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    bit x(n), y(n);
    for (int i = 1; i <= n; i++) {
        x.add(i, a[i - 1]);
        y.add(i, b[i - 1]);
    }
    int m; cin >> m;
    while (m--) {
        int k, l, r; cin >> k >> l >> r;
        bit& sum = k == 1 ? x : y;
        cout << (sum.query(r) - sum.query(l - 1)) << (m ? "\n" : "");
    }
    return 0;
}