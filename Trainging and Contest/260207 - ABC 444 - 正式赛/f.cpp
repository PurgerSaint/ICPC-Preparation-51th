#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

ll solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    ll mx = 0;
    for (ll& t: a) {
        cin >> t;
        mx = max(mx, t);
    }

    ll l = 1, r = mx;
    ll ans = 0;

    auto get = [&](ll len, ll x) -> ll {
        if (len < x) return 0;
        if (len < 2 * x) return 1;
        return len / x;
    };

    auto check = [&](ll x) -> bool {
        if (x == 0) return false;

        ll req = (n + m) / 2 + 1;
        ll can_keep = 0, need_m = 0;
        for (ll& val: a) {
            if (val < x) continue;
            can_keep += val / x;
            need_m += (val / x) - 1;
        }
        if (need_m > m) return false;
        ll surplus = m - need_m;
        return can_keep - surplus >= req;
    };

    while (l <= r) {
        ll mid = (l + (r - l) / 2);
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}