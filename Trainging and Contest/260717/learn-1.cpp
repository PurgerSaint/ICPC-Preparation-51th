#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; ll l, r; cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    if (n == 1) return 0;
    sort(range(a));
    ll ans = 0;
    for (auto i = a.begin(); i != a.end(); i++) {
        if (*i > r) continue;
        auto l_t = lower_bound(i + 1, a.end(), l - *i);
        auto r_t = upper_bound(i + 1, a.end(), r - *i);
        ans += r_t - l_t;
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}