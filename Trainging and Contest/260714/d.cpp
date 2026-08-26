#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), pre(n, 0);
    for (ll& t: a) cin >> t;
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    vector<int> b(m);
    for (int& t: b) cin >> t;
    sort(b.begin(), b.end());
    ll ans = 0;
    if (b.back() < n) ans = pre[n - 1] - pre[b.back() - 1];
    for (auto it = b.rbegin(); it != b.rend(); it++) {
        int j = *it - 1, i = -1;
        if (it + 1 != b.rend()) i = *(it + 1) - 1;
        ll sum = pre[j] - (i != -1 ? pre[i] : 0);
        ans += max(sum, -sum);
    }
    return ans;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0;
}