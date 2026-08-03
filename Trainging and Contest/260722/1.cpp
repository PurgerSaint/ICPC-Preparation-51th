#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    ll n, x; cin >> n >> x;
    vector<tuple<ll, ll, ll>> t(n);
    ll mx_step = 0, full_step = 0;
    for (auto& [a, b, c]: t) {
        cin >> a >> b >> c;
        mx_step += (b - 1) * a;
        full_step = max(full_step, a * b - c);
    }
    if (1 <= x && x <= mx_step) return 0;
    if (full_step <= 0) return -1;
    ll dic = x - mx_step;
    if (dic > 0) return (dic / full_step) + (dic % full_step ? 1 : 0);
    return -1;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}