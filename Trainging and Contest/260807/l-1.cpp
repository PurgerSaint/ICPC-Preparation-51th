#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<ll> num, tree, lazy;

void push_up(int p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = num[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void apply(int p, int l, int r, ll k) {
    tree[p] += (r - l + 1) * k;
    lazy[p] += k;
}

void push_down(int p, int l, int r) {
    if (lazy[p] == 0) return;
    int mid = l + ((r - l) >> 1);
    apply(p << 1, l, mid, lazy[p]);
    apply(p << 1 | 1, mid + 1, r, lazy[p]);
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        apply(p, l, r, val);
        return;
    }
    push_down(p, l, r);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update(p << 1, l, mid, ql, qr, val);
    if (mid < qr)
        update(p << 1 | 1, mid + 1, r, ql, qr, val);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    ll ans = 0;
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr)
        ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    num = vector<ll>(n + 1);
    tree = vector<ll>(n << 2);
    lazy = vector<ll>(n << 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    build(1, 1, n);
    while (m--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            ll k; cin >> k;
            update(1, 1, n, x, y, k);
        } else {
            cout << query(1, 1, n, x, y) << (m ? "\n" : "");
        }
    }
    return 0;
}
