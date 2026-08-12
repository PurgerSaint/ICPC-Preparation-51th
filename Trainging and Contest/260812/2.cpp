#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<ll> memo;
ll dfs(int i, int& n, vector<int>& a, map<int, vector<int>>& mp) {
    if (i > 2 * n) return 0;
    if (memo[i] != -1) return memo[i];
    int& x = mp[a[i]][0], y = mp[a[i]][1];
    ll ans = 0;
    if (x == i) {
        ans += 1LL * (y - x + 1) * (y - x + 1);
        ans += dfs(y + 1, n, a, mp);
        // memo[i] = max(memo[i], ans);
    }
    ans = max(ans, 1 + dfs(i + 1, n, a, mp));
    return memo[i] = ans;
}

ll solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    memo = vector<ll>(2 * n + 1, -1);
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    return dfs(1, n, a, mp);
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}
