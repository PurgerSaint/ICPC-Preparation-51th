#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> b;
    for (ll& t: a) {
        cin >> t;
        if (b.empty() || b.back().first != t) b.push_back({t, 0});
        b.back().second++;
    }
    if ((int)b.size() == 1) return 0;
    ll ans = 0;
    // for (auto& [num, cnt]: b)
    //     cout << num << " " << cnt << "\n";
    for (auto it = b.begin(); it + 1 != b.end(); it++) {
        auto& [num, cnt] = *it;
        auto& [next_num, next_cnt] = *(it + 1);
        if (num < next_num) {
            // cout << "add-1:" << num << " " << cnt << "\n"; 
            ans += cnt;
        } else if (num > next_num) {
            // cout << "add-2:" << num << " " << next_cnt << "\n"; 
            ans += next_cnt;
        }
        next_cnt += cnt;
        next_num = max(num, next_num);
        // cout << num << " " << cnt << " next:" << next_num << " " << next_cnt << "\n";
    }
    return ans;
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
