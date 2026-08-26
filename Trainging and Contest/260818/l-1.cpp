#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int n1, n2;
string s, t; 
vector<bool> v(26, 0);
vector<vector<bool>> vis(26, vector<bool>(26, 0));
vector<vector<int>> memo;
int dfs(int i, int x) {
    if (i >= n1) return 0;
    if (memo[i][x] != -1) return memo[i][x];
    int ans = 0, res = dfs(i + 1, x);
    if (!v[s[i] - 'a']) {
        ans = 1 + res;
    } else {
        if (0 <= x && x < 26 && !vis[x][s[i] - 'a']) {
            ans = 1 + dfs(i + 1, s[i] - 'a');
        } else if (x == 26) {
            ans = 1 + dfs(i + 1, s[i] - 'a');
        }
    }
    ans = max(ans, res);
    return memo[i][x] = ans;
}

int main() {
    ios;
    cin >> s >> t;
    n1 = s.length();
    n2 = t.length();
    for (char c: t) {
        int loc1 = c - 'a';
        for (int i = 0; i < 26; i++)
            if (v[i]) vis[i][loc1] = 1;
        v[loc1] = 1;
    }
    memo = vector<vector<int>>(n1, vector<int>(28, -1));
    cout << dfs(0, 26);
    return 0;
}