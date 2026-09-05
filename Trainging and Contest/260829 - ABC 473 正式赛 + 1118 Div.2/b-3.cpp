#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

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
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(range(b));
    b.erase(unique(range(b)), b.end());
    for (int i = 1; i <= n; i++)
        c[i] = lower_bound(range(b), a[i]) - b.begin();
    ll cnt = 0;
    bit bt(n);
    for (int i = 1; i <= n; i++) {
        cnt += bt.query(n) - bt.query(c[i]);
        bt.add(c[i], 1);
    }
    cout << cnt;
    return 0;
}