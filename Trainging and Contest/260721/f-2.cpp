#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(range(a));
    ll& nx = a[0], mx = a[n - 1];
    if (nx == mx) {
        cout << 0 << " " << (1LL * n * (n - 1) / 2);
        return 0;
    }
    int cnt_nx = 0, cnt_mx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == nx) cnt_nx++;
        else break;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == mx) cnt_mx++;
        else break;
    cout << (mx - nx) << " " << (1LL * cnt_nx * cnt_mx);
    return 0;
}