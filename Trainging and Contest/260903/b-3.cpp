#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int solve() {
    ll x, m; cin >> x >> m;
    set<ll> st;
    for (ll d = 1; d <= 2 * x; d++) {
        ll y = x ^ d;
        if ((y % d == 0 || x % d == 0) && x != y && 0 < y && y <= m) st.insert(y);
    }
    return st.size();
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