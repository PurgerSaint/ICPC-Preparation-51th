#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    string s, t; cin >> s >> t;
    int loc = 0;
    for (char c: s) {
        c == '+' ? loc++ : loc--;
    }
    int n = t.length();
    int offset = n;
    vector<vector<ld>> dp(n + 1, vector<ld>(2 * n + 1, 0.0L));
    dp[0][offset] = 1.0L;
    for (int i = 0; i < n; i++) {
        for (int pos = -n; pos <= n; pos++) {
            ld& pro = dp[i][pos + offset];
            if (pro == 0.0L) continue;

            if (t[i] == '+')
                dp[i + 1][pos + 1 + offset] += pro;
            else if (t[i] == '-')
                dp[i + 1][pos - 1 + offset] += pro;
            else {
                dp[i + 1][pos + 1 + offset] += pro * 0.5L;
                dp[i + 1][pos - 1 + offset] += pro * 0.5L;
            }
        }
    }
    ld ans = 0.0L;
    if (-n <= loc && loc <= n) ans = dp[n][loc + offset];
    cout << fixed << setprecision(12) << ans;
    return 0;
}

