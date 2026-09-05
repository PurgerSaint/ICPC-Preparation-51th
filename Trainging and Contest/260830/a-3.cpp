#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, q, b; cin >> n >> q >> b;
    vector<ll> a(n + 1), s(n + 1, 0);
    vector<bool> vis(n + 1, 0);
    vis[1] = b ? 1 : 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (i > 1) vis[i] = !vis[i - 1];
    }
    while (q--) {
        ll t; cin >> t;
        auto it = lower_bound(range(s), t);
        int pos = it - s.begin();
        cout << vis[pos] << " ";
        cout << pos << " ";
        cout << (t - s[pos - 1]);
        if (q) cout << "\n";
    }
    return 0;
}
