#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll solve() {
    ll n, x, y; cin >> n >> x >> y;
    ll k = lcm(x, y);
    ll x_size = (n / x) - (n / k), y_size = (n / y) - (n / k);
    ll x_sum = (x_size * (n - x_size + 1 + n) / 2), y_sum = (y_size * (y_size + 1) / 2);
    return x_sum - y_sum;
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