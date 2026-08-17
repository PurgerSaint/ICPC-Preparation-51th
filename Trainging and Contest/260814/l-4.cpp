#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const ll INF = -(1LL << 60);
vector<ll> tree;

void push_up(int p) {
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

void update(int p, int l, int r, int pos, ll k) {
    if (l == r) {
        tree[p] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(p << 1, l, mid, pos, k);
    else
        update(p << 1 | 1, mid + 1, r, pos, k);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    int mid = (l + r) >> 1;
    ll ans = INF;
    if (ql <= mid)
        ans = max(ans, query(p << 1, l, mid, ql, qr));
    if (mid < qr)
        ans = max(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}

int main() {
    ios;
    int n, l, r; cin >> n >> l >> r;
    vector<ll> num(n + 1);
    for (ll& t: num) cin >> t;
    vector<ll> dp(n + 1, INF);
    tree = vector<ll>((n + 1) << 2, INF);
    dp[0] = num[0];
    update(1, 0, n, 0, dp[0]);
    for (int i = l; i <= n; i++) {
        int l1 = max(0, i - r), r1 = i - l;
        ll mx = query(1, 0, n, l1, r1);
        if (mx != INF) {
            dp[i] = mx + num[i];
            update(1, 0, n, i, dp[i]);
        }
    }
    cout << query(1, 0, n, max(n - r + 1, 0), n);
    return 0;
}