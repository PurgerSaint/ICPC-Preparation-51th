#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const int MOD = 1e9 + 7;
ll fp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        a[i] = val % 2;
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if ((a[x - 1] + a[y - 1]) % 2 == 1)
            cout << "odd";
        else cout << "even";
        if (q != 0) cout << "\n";
    }
    return 0;
}