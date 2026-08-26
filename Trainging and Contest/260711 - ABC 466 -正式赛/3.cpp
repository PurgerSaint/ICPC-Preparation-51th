#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    vector<pair<int, int>> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 || cnt.back().first != a[i]) cnt.push_back({a[i], 1});
        else cnt.back().second++;
        sum += a[i];
    }
    int sz = cnt.size();
    vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, 0));
    int mx = -1;
    for (int i = 1; i <= sz; i++) {
        for (int j = i; j <= sz; j++) {
            if (cnt[j - 1].first) dp[i][j] = dp[i][j - 1] - cnt[j - 1].second;
            else dp[i][j] = dp[i][j - 1] + cnt[j - 1].second;
            mx = max(mx, dp[i][j]);
        }
    }
    cout << sum + mx;
    return 0;
}