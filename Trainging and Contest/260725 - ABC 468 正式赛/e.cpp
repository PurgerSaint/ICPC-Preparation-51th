#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % m + m) % m
#define range(a) a.begin(),a.end()
const ll MOD = 998244353;

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> inv(n + 1, 1);
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    
    vector<ll> h(n + 1, 0);
    for (int i = 1; i <= n; i++)
        h[i] = mod(h[i - 1] + inv[i], MOD);

    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
        s[i] = mod(s[i - 1] + h[i], MOD);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = mod(ans + a[i] * mod(s[n] - s[n - i] - s[i - 1], MOD), MOD);
    }
    cout << ans;
    return 0;
}
