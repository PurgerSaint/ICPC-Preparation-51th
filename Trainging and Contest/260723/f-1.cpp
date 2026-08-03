#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    ll n, k; cin >> n >> k;
    if (n <= k) return 1;
    ll ans = n;
    for (ll i = sqrt(n); i >= 1; i--) {
        if (!(n % i)) {
            if (i <= k) ans = min(ans, n / i);
            if ((n / i) <= k) ans = min(ans, i);
        }
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