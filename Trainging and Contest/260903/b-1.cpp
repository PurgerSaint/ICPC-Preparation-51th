#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

vector<int> tree, num;

void push_up(int p) {
    tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
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

int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    int mid = (l + r) >> 1, ans = INT_MAX;
    if (ql <= mid) ans = min(ans, query(p << 1, l, mid, ql, qr));
    if (mid < qr) ans = min(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    num = vector<int>(n + 1);
    tree = vector<int>(4 * n + 1, INT_MAX);
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    build(1, 1, n);
    while (m--) {
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r) << (m ? " " : "");
    }
    return 0;
}
