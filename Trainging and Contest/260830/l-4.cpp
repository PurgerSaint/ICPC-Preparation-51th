#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll q; cin >> n >> q;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(range(a));
    while (q--) {
        ll c; cin >> c;
        auto it = lower_bound(range(a), c);
        if (it == a.end() || *it != c) cout << -1;
        else cout << (it - a.begin() + 1);
        if (q) cout << " ";
    }
    return 0;
}