#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % m + m) % m
#define range(a) a.begin(),a.end()

const int MOD = 1e9 + 7;
vector<int> dp;

ll dfs(int m, vector<int>& coin) {
    if (m == 0) return 1;
    if (dp[m] != -1) return dp[m];
    ll ans = 0;
    for (int& c: coin) {
        if (m >= c) ans = mod(ans + dfs(m - c, coin), MOD);
    }
    dp[m] = ans;
    return ans;
}

int main() {
    ios;
    int n, w; cin >> n >> w;
    dp = vector<int>(w + 1, -1);
    vector<int> coin(n);
    for (int& c: coin) cin >> c;
    cout << dfs(w, coin);
    return 0;
}