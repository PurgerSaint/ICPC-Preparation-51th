#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll suf_sum = accumulate(range(a), 0LL) - a[0], pre_sum = 0;
    ll ans = -suf_sum;
    for (int i = 1; i < n; i++) {
        suf_sum -= a[i];
        ans = max(ans, a[0] + pre_sum - suf_sum);
        pre_sum += abs(a[i]);
    }
    return ans;
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