#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

pair<ll, ll> solve() {
    ll n, m; cin >> n >> m;
    ll nx = n / m, cnt_nx = (nx + 1) * nx / 2 * (n % m) + nx * (nx - 1) / 2 * (m - (n % m));
    // cout << nx << "\n";
    ll mx = n - (m - 1), cnt_mx = mx * (mx - 1) / 2;
    return {min(cnt_mx, cnt_nx), max(cnt_mx, cnt_nx)};
}

int main() {
    ios;
    auto [nx, mx] = solve();
    cout << nx << " " << mx;
    return 0;
}