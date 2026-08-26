#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

map<int, vector<int>> mp;
vector<int> a;
vector<ll> memo;
int n;
ll dfs(int i) {
    if (i >= 2 * n) return 0;
    if (memo[i] != -1) return memo[i];
    int l = mp[a[i]][0], r = mp[a[i]][1];
    ll ans = 0;
    if (i == r) ans = 1 + dfs(r + 1); 
    else {
        ans = max(1 + dfs(l + 1), 1LL * (r - l + 1) * (r - l + 1) + dfs(r + 1));
    }
    return memo[i] = ans;
}

ll solve() {
    cin >> n;
    mp.clear();
    a = vector<int>(2 * n);
    memo = vector<ll>(2 * n, -1);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    return dfs(0);
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