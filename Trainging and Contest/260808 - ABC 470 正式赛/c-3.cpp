#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    ll a, b, x; cin >> a >> b >> x;
    if (a == b) return 0;
    ll ans = INT_MAX, cnt = 0;
    while (a != b) {
        if (b > a) swap(a, b);
        ans = min(ans, a - b + cnt);
        a /= x;
        cnt++;
    }
    return min(ans, cnt);
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
