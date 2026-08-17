#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int T, n;
vector<pair<int, ll>> a;
vector<vector<ll>> memo;

ll dfs(int i, int t) {
    if (t <= 0 || i >= n) return 0;
    if (memo[i][t]) return memo[i][t];
    ll ans = -1;
    if (t >= a[i].first) {
        ll res = dfs(i + 1, t - a[i].first);
        if (res != -1) ans = a[i].second + res;
    }
    ll res = dfs(i + 1, t);
    if (res != -1) ans = max(ans, res);
    return memo[i][t] = ans;
}

int main() {
    ios;
    cin >> T >> n;
    a = vector<pair<int, ll>>(n);
    memo = vector<vector<ll>>(n, vector<ll>(T + 1, 0));
    for (auto& [t, c]: a)
        cin >> t >> c;
    cout << dfs(0, T);
    return 0;
}