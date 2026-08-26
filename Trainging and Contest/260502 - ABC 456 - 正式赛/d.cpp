#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const ll MOD = 998244353;

int main() {
    ios;
    string s; cin >> s;
    
    vector<int> dp(3, 0);

    for (char ch: s) {
        int x = ch - 'a';
        ll add = 1;

        for (int i = 0; i < 3; i++) {
            if (i == x) continue;
            add = (add + dp[i]) % MOD;
        }
        dp[x] = (dp[x] + add) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++)
        ans = (ans + dp[i]) % MOD;
    cout << ans;
    
    return 0;
}