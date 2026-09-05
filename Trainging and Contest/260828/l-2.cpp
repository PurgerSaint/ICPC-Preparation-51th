#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll m; cin >> n >> m;
    vector<vector<ll>> cnt(n, vector<ll>(26, 0));
    vector<ll> total(26, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c: s) {
            int j = c - 'A';
            cnt[i][j]++;
            total[j]++;
        }
    }
    for (int p = 0; p < n; p++) {
        bool f = 1;
        auto check = [&](int k) -> bool {
            for (int c = 0; c < 26; c++) {
                ll ot = total[c] - cnt[p][c];
                if (ot * m < cnt[p][c] + ot * k) return 0;
            }
            return 1;
        };
        ll l = 0, r = m, ans = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << ans << (p < n - 1 ? " " : "");
    }
    return 0;
}