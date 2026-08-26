#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; ll l; cin >> n >> l;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(a.begin(), a.end());
    ll max_diff = a[0];
    for (int i = 1; i < n; i++) {
        ll d = a[i] - a[i - 1];
        max_diff = max(max_diff, d);
    }
    max_diff = max(max_diff, l - a.back());
    double d = max_diff / 2.0;
    if (l > a.back() && (l - a.back()) - d > 1e-9)
        d = (l - a.back());
    if (a[0] > 0 && a[0] - d > 1e-9)
        d = a[0];
    printf("%.10f", d);
    return 0;
}