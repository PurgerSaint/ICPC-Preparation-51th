#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> lt(n);
    ll l = 0, r = 0;
    for (pair<ll, ll>& q: lt) {
        cin >> q.first >> q.second;
        r = max(r, q.second);
    }
    sort(lt.begin(), lt.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    ll ans = 0;
    auto check = [&](ll mid) -> bool {
        ll last = lt[0].second, cnt = 1;
        for (int i = 1; i < n; i++) {
            ll& l = lt[i].first, r = lt[i].second;
            if (l >= mid + last) {
                cnt++;
                last = r;
                if (cnt >= k) return true;
            }
        }
        return false;
    };
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    if (ans == 0) cout << -1;
    else cout << ans;
    return 0;
}