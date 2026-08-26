#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<int> memo;

int dfs(int m, vector<int>& coin) {
    if (m < 0) return -1;
    if (m == 0) return 0;
    if (memo[m] != -1) return memo[m];
    int ans = m;
    for (int& c: coin) {
        if (c > m) continue;
        int res = dfs(m - c, coin);
        if (res != -1) ans = min(ans, res + 1);
    }
    memo[m] = ans;
    return ans;
}

int main() {
    ios;
    int n, w; cin >> n >> w;
    memo = vector<int>(w + 1, -1);
    vector<int> coin(n);
    for (int& c: coin) cin >> c;
    cout << dfs(w, coin);
    return 0;
}