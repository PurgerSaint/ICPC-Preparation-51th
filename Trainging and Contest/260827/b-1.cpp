#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<ll> num, tree, lazy;

void push_up(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void apply(int p, int l, int r, ll k) {
    tree[p] += (r - l + 1) * k;
    lazy[p] += k;
}

void push_down(int p, int l, int r) {
    if (l == r || !lazy[p]) return;
    int mid = (l + r) >> 1;
    apply(p << 1, l, mid, lazy[p]);
    apply(p << 1 | 1, mid + 1, r, lazy[p]);
    lazy[p] = 0;
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

void update(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        apply(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, k);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (ql <= mid) ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr) ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans; 
}

int main() {
    ios;
    int n, q; cin >> n >> q;
    num = vector<ll>(n + 1);
    tree = lazy = vector<ll>(4 * n + 1);
    for (int i = 1; i <= n; i++) cin >> num[i];
    build(1, 1, n);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            ll k; cin >> k;
            update(1, 1, n, l, r, k);
        } else cout << query(1, 1, n, l, r) << (q ? "\n" : "");
    }
    return 0;
}