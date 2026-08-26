#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<bool>> vis(26, vector<bool>(26, 0));
vector<bool> v(26, 0);
string s, t;
int n;
vector<vector<int>> memo;
int dfs(int i, int x) {
    if (i >= (int)s.length()) return 0;
    if (memo[i][x] != -1) return memo[i][x];
    int loc = s[i] - 'a', ans = 0;
    if (v[loc]) {
        if (x == 26) ans = 1 + dfs(i + 1, loc);
        else if (!vis[x][loc]) ans = 1 + dfs(i + 1, loc);
    } else ans = 1 + dfs(i + 1, x);
    ans = max(ans, dfs(i + 1, x));
    return memo[i][x] = ans;
}

int main() {
    ios;
    cin >> s >> t;
    for (char c: t) {
        int loc = c - 'a';
        for (int i = 0; i < 26; i++) {
            if (v[i]) vis[i][loc] = 1;
        }
        v[loc] = 1;
    }
    n = s.length();
    memo = vector<vector<int>>(n, vector<int>(27, -1));
    cout << dfs(0, 26);
    return 0;
}