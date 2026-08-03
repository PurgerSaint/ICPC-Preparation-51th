#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        int cnt = 0;
        if (it == a.end()) cnt = n;
        else cnt = it - a.begin();
        cout << cnt;
        if (i < m - 1) cout << " ";
    }
    return 0;
}