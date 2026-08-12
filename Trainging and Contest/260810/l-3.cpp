#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % m + m) % m
#define range(a) a.begin(),a.end()

const int MOD = 1e9 + 7;
vector<int> coin;
vector<vector<ll>> dp;
int n;
ll dfs(int m, int i) {
    if (m < 0 || i == n) return 0;
    if (m == 0) return 1;
    if (dp[i][m] != -1) return dp[i][m];
    ll ans = mod(dfs(m - coin[i], i), MOD);
    ans = mod(ans + dfs(m, i + 1), MOD);
    return dp[i][m] = ans;
}

int main() {
    ios;
    int w; cin >> n >> w;
    coin = vector<int>(n);
    for (int& c: coin) cin >> c;
    dp = vector<vector<ll>>(n + 1, vector<ll>(w + 1, -1));
    cout << dfs(w, 0);
    return 0;
}
