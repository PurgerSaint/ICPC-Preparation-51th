#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<int> memo;
int dfs(int len, vector<int>& t) {
    if (len == 0) return 0;
    if (len < 0) return -1;
    if (memo[len] != -2) return memo[len];
    int ans = -1;
    for (int& i: t) {
        if (len >= i) {
            int res = dfs(len - i, t);
            if (res != -1) ans = max(ans, 1 + res);
        }
    }
    return memo[len] = ans;
}

int main() {
    ios;
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> t = {a, b, c};
    memo = vector<int>(n + 1, -2);
    cout << dfs(n, t);
    return 0;
}