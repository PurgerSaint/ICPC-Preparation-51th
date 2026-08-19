#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios;
    int x, y; cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        ll a = x - y;
        ll b = 1LL * y * (x - 1) - 1LL * i * (y - 1);
        ll t = gcd(a, b);
        cout << (a / t) << " " << (b / t);
        if (i < x) cout << "\n";
    }
    return 0;
}