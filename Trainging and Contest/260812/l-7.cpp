#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string s;
int n;
vector<vector<int>> memo;
int dfs(int i, int t) {
    if (i == n) return t == 0 ? 0 : -1;
    if (i > n || t < 0) return -1;
    int& ans = memo[i][t];
    if (ans != -2) return ans;
    ans = INT_MAX;
    int val = 0;
    for (int j = i; j < n; j++) {
        val = val * 10 + (s[j] - '0');
        if (val > t) break;
        int res = dfs(j + 1, t - val);
        if (res != -1) ans = min(ans, (i > 0) + res);
    }
    if (ans == INT_MAX) ans = -1;
    return ans;
}

int main() {
    ios;
    cin >> s;
    int t; cin >> t;
    n = s.length();
    memo = vector<vector<int>>(n, vector<int>(t + 1, -2));
    cout << dfs(0, t);
    return 0;
}
