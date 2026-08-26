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

void apply(int p, int l, int r, ll k) {
    tree[p] = (r - l + 1) - tree[p];
    lazy[p] ^= 1;
}

void push_down(int p, int l, int r) {
    if (l == r || lazy[p] == 0) return;
    int mid = (l + r) >> 1;
    apply(p << 1, l, mid, lazy[p]);
    apply(p << 1 | 1, mid + 1, r, lazy[p]);
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        apply(p, l, r, 1);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(p << 1, l, mid, ql, qr);
    if (mid < qr)
        update(p << 1 | 1, mid + 1, r, ql, qr);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (ql <= mid)
        ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr)
        ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    num = vector<ll>(n + 1, 0);
    lazy = tree = vector<ll>(n << 2, 0);
    while (m--) {
        int c, x, y; cin >> c >> x >> y;
        if (c == 0) {
            update(1, 1, n, x, y);
        } else {
            cout << query(1, 1, n, x, y) << (m ? "\n" : "");
        }
    }
    return 0;
}
