#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<ll> a(n), b(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            sum += a[i];
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        vector<pair<int, int>> rat1, rat2;
        for (int i = 1; i <= n; i++) {
            int r = lower_bound(b.begin(), b.end(), a[i - 1]) - b.begin();
            if (i % 2) rat1.push_back({i, r});
            else rat2.push_back({i, r});
        }
        sort(rat1.begin(), rat1.end(), [](pair<int, int>& x, pair<int, int>& y){ return x.second < y.second; });
        sort(rat2.begin(), rat2.end(), [](pair<int, int>& x, pair<int, int>& y){ return x.second < y.second; });
        int x1 = 0, x2 = 0;
        for (int i = 0; i < m; i++) {
            int t; cin >> t;
            vector<pair<int, int>>& r = t % 2 ? rat1 : rat2;
            bool rv = 0;
            if (!r.empty() && (a[r.back().first - 1] >= 0)) {
                sum -= a[r.back().first - 1];
                r.pop_back();
                rv = 1;
            }
            if (!rv && !r.empty() && (a[r.back().first - 1] < 0)) {
                int& cnt = t % 2 ? x1 : x2;
                if (cnt) continue;
                sum -= a[r.back().first - 1];
                r.pop_back();
            }
            if (t % 2) x1++;
            else x2++;
        }
        cout << sum << (tt ? "\n" : "");
    }
    return 0;
}