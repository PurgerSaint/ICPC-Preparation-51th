#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<ll> a, s;
void solve() {
    ll k, x; cin >> k >> x;
    ll kk = 1LL << k;
    if (x == 0 || x == kk * 2) {
        cout << -1 << "\n";
        return;
    }
    ll y = kk * 2 - x;
    vector<int> ans;
    while (x != kk) {
        if (x < y) {
            ans.push_back(1);
            y -= x;
            x *= 2;
        } else {
            ans.push_back(2);
            x -= y;
            y *= 2;
        }
    }
    cout << ans.size() << "\n";
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << (it + 1 != ans.rend() ? " " : "");
}

int main() {
    ios;
    a = vector<ll>(61);
    s = vector<ll>(61);
    a[0] = 1;
    s[0] = 1;
    for (int i = 1; i <= 60; i++) {
        a[i] = a[i  - 1] * 2;
        s[i] = s[i - 1] + a[i];
    }
    int tt; cin >> tt;
    while (tt--) {
        solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
