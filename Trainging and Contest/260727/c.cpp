#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
#define between(a, b, t) (a <= t && t <= b)

int solve() {
    int n; cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> a(n);
    for (auto& [p, q]: a) {
        auto& [l, r] = p;
        auto& [u, v] = q;
        cin >> l >> r >> u >> v;
    }
    for (int m = n; m >= 1; m--) {
        int len = 0;
        for (int i = 1; i <= n && len < m; i++) {
            auto& [p, q] = a[i - 1];
            auto& [l, r] = p;
            auto& [u, v] = q;
            int l_rk = len + 1, r_rk = m - l_rk + 1;
            if (!between(l, r, l_rk) && !between(u, v, r_rk)) len++; 
        }
        if (len == m) return m;
    }
    return 0;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
