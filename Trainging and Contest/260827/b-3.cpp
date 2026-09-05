#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<ll> num, tree, lazy_add, lazy_fix;
vector<bool> fix;

void push_up(int p) {
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
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

void apply_fix(int p, int l, int r, ll k) {
    tree[p] = k;
    lazy_fix[p] = k;
    lazy_add[p] = 0; 
    fix[p] = 1;
}

void apply_add(int p, int l, int r, ll k) {
    tree[p] += k;
    lazy_add[p] += k;
}

void push_down(int p, int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (fix[p]) {
        apply_fix(p << 1, l, mid, lazy_fix[p]);
        apply_fix(p << 1 | 1, mid + 1, r, lazy_fix[p]);
        fix[p] = 0;
        lazy_fix[p] = 0;
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

void update_fix(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        apply_fix(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_fix(p << 1, l, mid, ql, qr, k);
    if (mid < qr) update_fix(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ans = -(1LL << 60);
    if (ql <= mid) ans = max(ans, query(p << 1, l, mid, ql, qr));
    if (mid < qr) ans = max(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}

int main() {
    ios;
    int n, q; cin >> n >> q;
    num = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) cin >> num[i];
    tree = lazy_add = lazy_fix = vector<ll>(n * 4 + 1);
    fix = vector<bool>(4 * n + 1, 0);
    build(1, 1, n);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 3) cout << query(1, 1, n, l, r) << (q ? "\n" : "");
        else {
            ll k; cin >> k;
            if (t == 1) update_fix(1, 1, n, l, r, k);
            else update_add(1, 1, n, l, r, k);
        }
    }
    return 0;
}