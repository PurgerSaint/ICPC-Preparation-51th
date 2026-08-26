#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

ll dfs(ll x, ll& y, ll& k) {
    if (x == y) return 0;
    if (x * k <= y && y <= (x + 1) * k) {
        return 1;
    }
    if (x > y) {
        return dfs(x / k, y, k) + 1;
    } else {
        ll cnt = LLONG_MAX;
        for (ll i = 0; i < k; i++)
            cnt = min(cnt, dfs(x * k + i, y, k) + 1);
        if (cnt == LLONG_MAX) return 0;
        return cnt;
    }
}

ll solve() {
    ll x, y, k; cin >> x >> y >> k;
    return dfs(x, y, k);
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t ? "\n" : "");
    return 0;
}