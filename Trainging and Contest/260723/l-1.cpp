#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int t, m; cin >> t >> m;
    vector<pair<int, int>> p(m);
    for (auto& [time, cost]: p) cin >> time >> cost;
    vector<vector<int>> dp(m + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= m; i++) {
        auto& [time, cost] = p[i - 1];
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= time)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - time] + cost);
        }
    }
    cout << dp[m][t];
    return 0;
}