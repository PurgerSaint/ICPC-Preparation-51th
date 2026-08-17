#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            dp[i][j] += sum[j + 1] - sum[i];
        }
    }
    cout << dp[0][n - 1];
    return 0;
}