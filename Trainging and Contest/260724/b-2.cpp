#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string s, t;
int n, loc;
vector<vector<ld>> memo;
ld dfs(int i, int pos) {
    if (i == n) return pos == loc ? 1.0L : 0.0L;
    ld& ans = memo[i][pos + n];
    if (ans != -1.0L) return ans;
    char c = t[i];
    if (c == '+') return ans = dfs(i + 1, pos + 1);
    if (c == '-') return ans = dfs(i + 1, pos - 1);
    return ans = 0.5L * dfs(i + 1, pos + 1) + 0.5L * dfs(i + 1, pos - 1);
}

int main() {
    ios;
    cin >> s >> t;
    for (char c: s) c == '+' ? loc++ : loc--;
    n = t.length();
    
    memo = vector<vector<ld>>(n + 1, vector<ld>(2 * n + 1, -1.0L));
    cout << fixed << setprecision(12) << dfs(0, 0);
    return 0;
}