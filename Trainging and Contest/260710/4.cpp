#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (ll& t: a) cin >> t;
        for (ll& t: b) cin >> t;
        if (n == 1) {
            if (b[0] >= 2 || (b[0] == 1 && a[0] != 1)) cout << 1;
            else cout << 0;
            if (tt) cout << "\n";
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            ll req;
            if (i == 0) req = gcd(a[0], a[1]);
            else if (i == n - 1) req = gcd(a[n - 2], a[n - 1]);
            else {
                ll gl = gcd(a[i], a[i - 1]), gr = gcd(a[i], a[i + 1]);
                req = lcm(gl, gr);
            }

            if (req <= b[i] && req != a[i]) cnt++;
            else if (req <= b[i] && req == a[i]) {
                if (req * 2 <= b[i]) cnt++;
            }
        }
        cout << cnt << (tt ? "\n" : "");
    }
    return 0;
}