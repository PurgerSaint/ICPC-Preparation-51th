#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll solve() {
    ll k, x, y; cin >> k >> x >> y;
    vector<ll> ak;
    ll c = 1, lim = max(x, y);
    while (true) {
        ak.push_back(c);
        if (c > lim / (k + 1)) {
            ak.push_back(lim + 1);
            break;
        }
        c *= (k + 1);
    }
    if (x == y) return x;
    auto get_leave = [&](const ll& g) -> ll {
        auto it = lower_bound(range(ak), g);
        return it - ak.begin();
    };
    ll x_leave = get_leave(x), y_leave = get_leave(y);
    // cout << x_leave << " " << y_leave << "\n";
    auto up_leave = [&](ll& g, ll& leave, const ll& target) {
        while (true) {
            auto it = lower_bound(range(ak), g);
            leave = it - ak.begin();
            // cout << g << " " << leave << " " << target << "\n";
            if (leave <= target || leave == 0) return;
            auto pre = prev(it);
            g -= *pre;
            g = g / k + (g % k > 0);
        }
    };
    // cout << x << " " << x_leave << "\t" << y << " " << y_leave << "\n";
    while (x != y) {
        if (x_leave > y_leave) up_leave(x, x_leave, y_leave);
        else if (y_leave > x_leave) up_leave(y, y_leave, x_leave);
        else {
            up_leave(x, x_leave, x_leave - 1);
            up_leave(y, y_leave, y_leave - 1);
        }
    }
    return x;
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