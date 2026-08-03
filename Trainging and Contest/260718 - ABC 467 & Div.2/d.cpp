#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
#define nx(a, b, c, d) min(a, min(b, min(c, d)))
#define mx(a, b, c, d) max(a, max(b, max(c, d)))

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

tuple<ll, ll, ll> get(ll px, ll py, ll qx, ll qy) {
    ll a = 2 * (qx - px), b = 2 * (qy - py);
    ll c = px * px + py * py - qx * qx - qy * qy;
    ll g = gcd(a, gcd(b, c));
    a /= g, b /= g, c /= g;
    if (a < 0) a = -a, b = -b, c = -c;
    if (a == 0 && b < 0) b =- b, c = -c;
    return {a, b, c};
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        ll px, py; cin >> px >> py;
        ll qx, qy; cin >> qx >> qy;
        ll rx, ry; cin >> rx >> ry;
        ll sx, sy; cin >> sx >> sy;
        
        auto [a1, b1, c1] = get(px, py, qx, qy);
        auto [a2, b2, c2] = get(rx, ry, sx, sy);

        if (a1 * b2 - a2 * b1 == 0) {
            if (a1 == a2 && b1 == b2 && c1 == c2) cout << "Yes";
            else cout << "No";
        } else cout << "Yes";
        
        if (tt) cout << "\n";
    }
    return 0;
}