#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;

    auto check = [&](ll diff) -> bool {
        ll mx = a[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - mx >= diff) {
                cnt++;
                mx = a[i];
            }
        }
        return cnt >= m;
    };

    sort(a.begin(), a.end());
    ll l = 0, r = a.back() - a.front();
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
    return 0;
}