#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

string solve() {
    ll n, m, a, b; cin >> n >> m >> a >> b;
    if (gcd(a, n) > 1 || gcd(b, m) > 1 || gcd(n, m) > 2) return "NO";
    return "YES";
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