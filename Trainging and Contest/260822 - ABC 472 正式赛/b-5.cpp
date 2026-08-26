#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll T; cin >> n >> T;
    vector<ll> x(5);
    for (int i = 1; i <= 4; i++) cin >> x[i];
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<ll, ll> dp[5];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        unordered_map<ll, ll> ndp[5];
        for (int t = 0; t <= 4; t++) {
            for (auto& [anger, score]: dp[t]) {
                ndp[0][anger] = max(ndp[0][anger], score);
                if (t + 1 < 5 && anger + x[t + 1] <= T) {
                    ll new_anger = anger + x[t + 1];
                    ndp[t + 1][new_anger] = max(ndp[t + 1][new_anger], score + a[i]);
                }
            }
        }
        for (int t = 0; t <= 4; t++)
            swap(dp[t], ndp[t]);
    }
    ll ans = 0;
    for (int t = 0; t <= 4; t++)
        for (auto& [_, score]: dp[t])
            ans = max(ans, score);
    cout << ans;
    return 0;
}