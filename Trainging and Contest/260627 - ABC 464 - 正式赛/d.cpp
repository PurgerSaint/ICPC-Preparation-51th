#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> x(n), y(n - 1);
    for (ll& t: x) cin >> t;
    for (ll& t: y) cin >> t;

    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = (s[0] == 'R' ? -x[0] : 0);   // 转为S的最终幸福感
    dp[0][1] = (s[0] == 'S' ? -x[0] : 0);   // 转为R的最终幸福感

    for (int i = 1; i < n; i++) {
        ll cost_S = (s[i] == 'R' ? x[i] : 0);
        ll cost_R = (s[i] == 'S' ? x[i] : 0);

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]) - cost_S;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - cost_R;
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}
int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve() << (t ? "\n" : "");
    }
    return 0;
}