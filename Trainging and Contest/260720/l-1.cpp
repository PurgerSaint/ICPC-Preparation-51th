#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] == -1) continue;
        if (i + c <= n) dp[i + c] = max(dp[i + c], dp[i] + 1);
        if (i + b <= n) dp[i + b] = max(dp[i + b], dp[i] + 1);
        if (i + a <= n) dp[i + a] = max(dp[i + a], dp[i] + 1);
    }
    cout << dp[n];
    return 0;
}