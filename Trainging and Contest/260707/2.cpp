#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t) (t % MOD + MOD) % MOD
#define mod_exp(t) (t % PHI + PHI) % PHI
const ll MOD = 998244353;
const ll PHI = MOD - 1;

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod(res * a);
        a = mod(a * a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        ll r, n, c, m; cin >> n >> m >> r >> c;
        ll count = mod_exp(mod_exp(n * m) - mod_exp((n - r + 1) * (m - c + 1)));
        cout << fast_pow(2, count);
        if (tt) cout << "\n";
    }
    return 0;
}