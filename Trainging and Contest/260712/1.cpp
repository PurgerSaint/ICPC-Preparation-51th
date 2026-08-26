#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n), b(n), s(n);
        vector<pair<ll, int>> cnt;
        map<ll, int> index;
        for (ll& t: a) {
            cin >> t;
            if (!index.count(t)) {
                index[t] = cnt.size();
                cnt.push_back({t, 1});
            } else cnt[index[t]].second++;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (i == 0) s[0] = b[0];
            else s[i] = s[i - 1] + b[i];
        }
        sort(cnt.begin(), cnt.end(), [](auto& x, auto& y){ return x.first < y.first; });
        int sz = cnt.size();
        for (int i = sz - 2; i >= 0; i--) {
            cnt[i].second += cnt[i + 1].second;
        }
        ll ans = 0;
        for (int i = 0; i < sz; i++) {
            ll poi = 0;
            auto& [diff, ct] = cnt[i];
            auto it = lower_bound(s.begin(), s.end(), ct);
            if (it == s.end()) poi = n * diff;
            else if ((*it) > ct) {
                if (it == s.begin()) poi = 0;
                else {
                    poi = (it - s.begin()) * diff;
                }
            } else poi = (it - s.begin() + 1) * diff;
            ans = max(ans, poi);
        }
        cout << ans << (tt ? "\n" : "");
    }
    return 0;
}