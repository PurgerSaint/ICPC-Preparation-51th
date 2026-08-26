#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n, k, p, m; cin >> n >> k >> p >> m;
        vector<ll> a(n + 1), cost, mk;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i != p) {
                cost.push_back(a[i]);
                if (p > k && i < p) mk.push_back(a[i]);
            }
        }
        sort(range(cost));
        sort(range(mk));
        ll pp = a[p], pn = a[p];
        if (p > k) {
            for (int i = 0; i < p - k; i++)
                pp += mk[i];
        }
        m -= pp;
        if (m < 0) {
            cout << 0 << (tt ? "\n" : "");
            continue;
        }
        for (int i = 0; i < n - k; i++)
            pn += cost[i];
        cout << 1 + m / pn << (tt ? "\n" : "");
    }
    return 0;
}