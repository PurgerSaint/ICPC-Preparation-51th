#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int ans = 0;
    sort(range(a));
    for (int l = 1; l <= a.back(); l++) {
        int cnt = a.end() - lower_bound(range(a), l);
        cnt += upper_bound(range(a), 2 * l) - lower_bound(range(a), 2 * l);
        ans = max(ans, cnt);
        cout << l << " " << cnt << "\n";
    }
    return ans;
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