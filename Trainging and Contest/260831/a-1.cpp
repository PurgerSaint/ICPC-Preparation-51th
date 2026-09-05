#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll k;
    cin >> n >> k;
    map<ll, int> dp;
    dp[0] = 0;
    ll pre = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        pre = mod(pre + t, k);
        
        if (dp.count(pre))
            cnt = max(cnt, dp[pre] + 1);
        
        dp[pre] = max(dp[pre], cnt);
    }
    cout << cnt;
    return 0;
}