#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<ll> num, tree, lazy_add, lazy_mu;
ll MOD;

void push_up(int p) {
    tree[p] = mod(tree[p << 1] + tree[p << 1 | 1], MOD);
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void apply_add(int p, int l, int r, ll k) {
    tree[p] = mod(tree[p] + (r - l + 1) * k, MOD);
    lazy_add[p] = mod(lazy_add[p] + k, MOD);
}

void apply_mu(int p, int l, int r, ll k) {
    tree[p] = mod(tree[p] * k, MOD);
    lazy_add[p] = mod(lazy_add[p] * k, MOD);
    lazy_mu[p] = mod(lazy_mu[p] * k, MOD);
}

void push_down(int p, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (lazy_mu[p] != 1) {
        apply_mu(p << 1, l, mid, lazy_mu[p]);
        apply_mu(p << 1 | 1, mid + 1, r, lazy_mu[p]);
        lazy_mu[p] = 1;
    }
    if (lazy_add[p]) {
        apply_add(p << 1, l, mid, lazy_add[p]);
        apply_add(p << 1 | 1, mid + 1, r, lazy_add[p]);
        lazy_add[p] = 0;
    }
}

void update_add(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        apply_add(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_add(p << 1, l, mid, ql, qr, k);
    if (mid < qr) update_add(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

void update_mu(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        apply_mu(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_mu(p << 1, l, mid, ql, qr, k);
    if (mid < qr) update_mu(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (ql <= mid) ans = mod(ans + query(p << 1, l, mid, ql, qr), MOD);
    if (mid < qr) ans = mod(ans + query(p << 1 | 1, mid + 1, r, ql, qr), MOD);
    return ans;
}

int main() {
    ios;
    int n, q; cin >> n >> q >> MOD;
    num = vector<ll>(n + 1);
    tree = lazy_add = vector<ll>(4 * n + 1);
    lazy_mu = vector<ll>(4 * n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> num[i];
    build(1, 1, n);
    while (q--) {
        int k, l, r; cin >> k >> l >> r;
        if (k == 3) cout << query(1, 1, n, l, r) << (q ? "\n" : "");
        else {
            ll x; cin >> x;
            if (k == 1) update_mu(1, 1, n, l, r, x);
            else update_add(1, 1, n, l, r, x);
        }
    }
    return 0;
}