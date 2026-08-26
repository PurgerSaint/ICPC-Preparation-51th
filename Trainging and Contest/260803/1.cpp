#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(range(a));

    int med = n / 2;
    auto check = [&](ll mid) -> bool {
        if (a[med] == mid) return 1;
        ll sum = 0;
        for (int i = med; i < n; i++) {
            if (a[i] > mid) break;
            sum += mid - a[i];
            if (sum > k) return false;
        }
        return true;
    };

    ll l = a[0], r = a[n - 1] + k, ans = a[med];
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}