#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const ll MOD = 998244353;

int main() {
    ios;
    string s; cin >> s;
    int n = s.size();
    
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            dp[i] = (dp[i - 1] + 1) % MOD;
    
    cout << (accumulate(dp.begin(), dp.end(), 0LL) % MOD);
    
    return 0;
}