#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const int MAX = 200000;
const int MOD = 998244353;
vector<ll> fact(MAX + 1);

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * fast_pow(fact[k], MOD-2) % MOD * fast_pow(fact[n-k], MOD-2) % MOD;
}

int main() {
    ios;
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    ll c1 = C(n - 1, k - 1), c2 = k >= 2 ? C(n - 2, k - 2) : 0;
    ll sum = 0, s1 = 0;
    for (ll& t: a) {
        cin >> t;
        sum = mod(sum + t, MOD);
        s1 = mod(s1 + mod(t * t, MOD), MOD);
    }
    sum = mod(sum * sum, MOD);
    cout << mod(mod(c1 * s1, MOD) + mod(c2 * (sum - s1), MOD), MOD);
    return 0;
}