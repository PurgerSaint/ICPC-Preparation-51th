#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const double eps = 1e-9;
bool same(double a, double b) { return abs(a - b) < eps; }  // 等于
bool l(double a, double b) { return a - b > eps; }          // 大于
bool r(double a, double b) { return a - b < -eps; }         // 小于
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll k; cin >> k;
    double a1 = a, b1 = b, c1 = c, all = a * b * c;
    double t = 0;
    ll i = 0, j = 0;
    // cout << "1===\n";
    for (ll x = 0; x <= k; x++) {
        // cout << "2 - " << x << "===\n";
        double a2 = x == 0 ? a1 : (a1 / x);
        for (ll y = 0; y <= (x == 0 ? k: (k / x)); y++) {
            // cout << "3 - " << y << "===\n";
            double b2 = y == 0 ? b1 : (b1 / y);
            if (!same(a2, b2) || l(a2 * b2, all)) continue;
            for (ll z = 0; z <= (x == 0 || y == 0 ? k : (k / (x * y))); z++) {
                // cout << "4 - " << z << "===\n";
                double c2 = z == 0 ? c1 : (c1 / z);
                if (!same(a2, c2) || !same(b2, c2) || l(a2 * b2 * c2, all)) continue;
                if (same(a2 * b2 * c2, all) && l(c2, t)) {
                    t = c2;
                    i = c, j = z;
                }
            }
        }
    }
    // cout << "5===\n";
    // cout << i << " " << j << "\n";
    ll g = gcd(i, j);
    cout << (i / g) << " " << (j / g); 
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}