#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int solve() {
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + (s[0][i] != s[1][i]));
        if (i + 1 < n)
            dp[i + 2] = min(dp[i + 2], dp[i] + (s[0][i] != s[0][i + 1]) + (s[1][i] != s[1][i + 1]));
    }
    return dp[n];
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0; 
}