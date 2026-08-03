#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(a.begin(), a.end());
    if (a[0] > 0) return a[n - 1] * n;
    vector<ll> k(n);
    k[0] = a[n - 1];
    a.pop_back();
    auto it = unique(a.begin(), a.end());
    for (int i = 1; i < n; i++)
        k[i] = a[i - 1];
    ll sum = 0;
    set<ll> b;
    ll mex = 0;
    for (int i = 0; i < n; i++) {
        b.insert(k[i]);
        while (b.count(mex)) mex++;
        sum += mex;
    }
    return sum + a[n - 1] * n;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0;
}