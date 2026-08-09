#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> mn1(n, INT_MAX), mn2(n, INT_MAX);
    vector<bool> r(n, 0), c(n, 0);
    int cnt = n * n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] <= 0) {
                sum += a[i][j];
                r[i] = 1;
                c[j] = 1;
                cnt--;
            }
            mn1[i] = min(mn1[i], a[i][j]);
        }
    }
    // cout << cnt << " " << sum << "\n";
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++)
            mn2[j] = min(mn2[j], a[i][j]);
    }
    ll r_sum = sum, c_sum = sum;
    for (int i = 0; i < n; i++) {
        if (mn1[i] <= 0) continue;
        r_sum += mn1[i];
    }
    for (int j = 0; j < n; j++) {
        if (mn2[j] <= 0) continue;
        c_sum += mn2[j];
    }
    return min(r_sum, c_sum);
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << fixed << setprecision(12) << solve();
        if (t) cout << "\n";
    }
    return 0;
}
