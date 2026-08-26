#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
const ll MOD = 1e9 + 7;
#define mod(t) (t % MOD + MOD) % MOD

ll fp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod((res * a));
        a = mod((a * a));
        b >>= 1;
    }
    return res;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (ll& t: a) cin >> t;
        int d = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) d++;
            if (a[i] > 0 && i > 0 && a[i] - 1 == a[i - 1]) l++;
        }
        ll cnt = fp(2, n - d);
        if (a[0] == -1) cnt = mod((cnt * (l + 1)));
        cout << cnt << (tt ? "\n" : "");
    }
    return 0;
}