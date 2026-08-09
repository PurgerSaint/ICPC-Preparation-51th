#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<ll> tree, lazy;

void push_up(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void apply(int p, int l, int r, ll k) {
    tree[p] += (r - l + 1) * k;
    lazy[p] += k;
}

void push_down(int p, int l, int r) {
    if (l == r || lazy[p] == 0) return;
    int mid = (l + r) >> 1;
    apply(p << 1, l, mid, lazy[p]);
    apply(p << 1 | 1, mid + 1, r, lazy[p]);
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        apply(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(p << 1, l, mid, ql, qr, k);
    if (mid < qr)
        update(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int ans = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr)
        ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> b = a;
    sort(range(b));
    b.erase(unique(range(b)), b.end());
    int sz = b.size();
    tree = lazy = vector<ll>(sz << 2, 0);
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        c[i] = lower_bound(range(b), a[i]) - b.begin() + 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] < sz) ans += query(1, 1, sz, c[i] + 1, sz);
        update(1, 1, sz, c[i], c[i], 1);
    }
    cout << ans;
    return 0;
}
