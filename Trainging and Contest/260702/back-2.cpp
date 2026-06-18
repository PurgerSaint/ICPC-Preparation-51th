#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct bit {
    int n;
    vector<ll> tree;
    bit(int a): n(a), tree(n + 2, 0) {}
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
    vector<ll> a(n), sort_a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sort_a[i] = a[i];
    }
    sort(sort_a.begin(), sort_a.end());
    sort_a.erase(unique(sort_a.begin(), sort_a.end()), sort_a.end());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(sort_a.begin(), sort_a.end(), a[i]) - sort_a.begin() + 1;

    bit b(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - b.query(a[i]);
        b.add(a[i], 1);
    }
    cout << ans;
    return 0;
}