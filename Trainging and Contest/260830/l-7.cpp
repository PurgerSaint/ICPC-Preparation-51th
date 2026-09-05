#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll x; cin >> n >> x;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] + a[i] > x) {
            int cnt = (a[i - 1] + a[i]) - x;
            ans += cnt;
            if (a[i] >= cnt) a[i] -= cnt, cnt = 0;
            else cnt -= a[i], a[i] = 0;
            if (cnt > 0) a[i - 1] -= cnt;
        }
    }
    cout << ans;
    return 0;
}