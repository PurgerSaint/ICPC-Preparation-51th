#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    ll n, k; cin >> n >> k;
    vector<vector<ll>> a(n);
    vector<ll> sz(n);
    for (int i = 0; i < n; i++) {
        vector<ll>& us = a[i];
        cin >> sz[i];
        for (int j = 0; j < sz[i]; j++) {
            ll val; cin >> val;
            us.push_back(val);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll c; cin >> c;
        if (k == 0) continue;
        else if (k > c * sz[i]) {
            k -= c * sz[i];
        } else if (k < sz[i]) {
            ans = a[i][k - 1];
            k = 0;
        } else if (k % sz[i] == 0) {
            ans = a[i].back();
            k = 0;
        } else {
            ans = a[i][k % sz[i] - 1];
            k = 0;
        }
    }
    cout << ans;
    return 0;
}