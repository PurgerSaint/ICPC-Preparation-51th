#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(n - 1);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    vector<vector<ll>> g(m, vector<ll>(n, -1));
    for (int i = 0; i < m; i++)
        g[i][0] = i;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            g[i][j] = (b[j - 1] - g[i][j - 1] + m) % m;
        }
    }
    ll cnt = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        ll s_cnt = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j] != a[j])
                s_cnt++;
        }
        if (s_cnt) cnt = min(cnt, s_cnt);
    }
    cout << cnt;
    return 0;
}