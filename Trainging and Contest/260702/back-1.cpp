#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (ll& t: a) cin >> t;
        bool flag = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll t; cin >> t;
            sum += a[i] - t;
            if (sum > 0) flag = 0;
        }
        cout << (flag ? "Yes" : "No") << (tt ? "\n" : "");
    }
    return 0;
}