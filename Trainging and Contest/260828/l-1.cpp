#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll solve() {
    int n; ll h, k; cin >> n >> h >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    if (h >= sum) {
        ans = n * (h / sum) + k * (h / sum - (h % sum == 0));
        h = h % sum;
    }
    vector<ll> b(n, 0);
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        b[i] = max(b[i + 1], a[i]);
    if (h) {
        ll pre = LLONG_MAX, s = 0;
        for (int i = 0; i < n; i++) {
            if (s >= h) break;
            s += a[i];
            ans++;
            pre = min(a[i], pre);
            if (i + 1 < n && s - pre + b[i + 1] >= h) {
                break;
            }
        }
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