#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n, d; cin >> n >> d;
    vector<int> diff(1e6 + 5, 0);
    for (int i = 0; i < n; i++) {
        int s, t; cin >> s >> t;
        if (t - s < d) continue;
        diff[s]++;
        diff[t - d + 1]--;
    }
    vector<int> a(1e6 + 5, 0);
    a[0] = diff[0];
    ll ans = 0;
    for (int x = 1; x <= 1e6; x++) {
        a[x] = a[x - 1] + diff[x];
        if (a[x] >= 2)
            ans += 1LL * a[x] * (a[x] - 1) / 2;
    }
    cout << ans;
    return 0;
}