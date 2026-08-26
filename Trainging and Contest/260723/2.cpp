#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    ll mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        ll s_mx = max(mx - a[i], b[i] - mn);
        ll s_mn = min(mn - a[i], b[i] - mx);
        mx = s_mx, mn = s_mn;
    }
    return mx;
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