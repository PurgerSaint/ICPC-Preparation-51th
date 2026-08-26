#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> b;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (t > 1) b.push_back(t);
        else cnt++;
    }
    if (b.empty()) return 0;
    ll ans = 0;
    sort(range(b), greater<ll>());
    if (b.size() == 1) {
        ll g = min(cnt, b[0] / 2);
        ans += b[0] + g;
        return ans < 3 ? 0 : ans;
    }
    for (int i = 0; i < (int)b.size(); i++) {
        ll& t = b[i];
        if (t > 2 && cnt > 0) {
            ll g = min(cnt, max(t / 2 - 1, 0LL));
            ans += g;
            cnt -= g;
        }
        ans += t;
    }
    return ans < 3 ? 0 : ans;
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
