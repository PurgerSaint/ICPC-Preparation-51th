#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const int MAXN = 3 * 1e5 + 5;
ll v, use = 0;
struct node {
    ll loc, time, w;
    node(): time(0), w(0) {};
};
vector<node> num, tree(MAXN << 2);

void push_up(int p) {
    if (tree[p << 1].w >= tree[p << 1 | 1].w) tree[p] = tree[p << 1];
    else tree[p] = tree[p << 1 | 1];
}

void update(int p, int l, int r, int pos, ll t, ll w) {
    if (l == r) {
        tree[p].loc = pos;
        tree[p].time = t;
        tree[p].w = w;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(p << 1, l, mid, pos, t, w);
    else
        update(p << 1 | 1, mid + 1, r, pos, t, w);
    push_up(p);
}

void update_range(int p, int l, int r, int ql, int qr, ll t) {
    if (ql <= l && r <= qr) {
        tree[p].w = min(v, max(tree[p].w + t - tree[p].time, 0LL));
        tree[p].time = t;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update_range(p << 1, l, mid, ql, qr, t);
    if (mid < qr)
        update_range(p << 1 | 1, mid + 1, r, ql, qr, t);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (l > r) return -1;
    if (ql <= l && r <= qr) {
        ll val = tree[p].w;
        update(1, 1, use, tree[p].loc, 0, 0);
        use--;
        return val;
    }
    ll ans = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        ans = max(ans, query(p << 1, l, mid, ql, qr));
    }
    if (mid < qr) {
        ans = max(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
    }
    return ans;
}

int main() {
    ios;
    int n; cin >> n >> v;
    while (n--) {
        ll c, t; cin >> c >> t;
        if (use) update_range(1, 1, use, 1, use, t);
        if (c == 1) {
            ll x; cin >> x;
            use++;
            update(1, 1, use, use, t, x);
        } else {
            cout << query(1, 1, use, 1, use);
            if (n) cout << "\n";
        }
    }
    return 0;
}