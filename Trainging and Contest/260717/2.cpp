#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    ll s, k, m; cin >> s >> k >> m;
    if (s == k) return s - m % s;
    ll t = (m / k) % 2; 
    if (s > k) {
        if (t) return k - m % k;
        return s - (m % k);
    } else return (m % k) >= s ? 0 : s - (m % k);
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