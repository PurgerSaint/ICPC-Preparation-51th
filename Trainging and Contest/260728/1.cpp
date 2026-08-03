#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n; ll x; cin >> n >> x;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (t >= x) b.push_back(t);
        else a.push_back(t);
    }
    sort(range(a));
    sort(range(b));
    deque<ll> dq;
    for (ll& t: a) dq.push_back(t);
    ll ans = 0, s = 0;
    vector<ll> c;
    while (!dq.empty()) {
        if (s % x + dq.back() >= x) {
            ans += dq.back();
            s += dq.back();
            c.push_back(dq.back());
            dq.pop_back();
        } else {
            // if (s % x + dq.front() >= x) ans += dq.front();
            s += dq.front();
            c.push_back(dq.front());
            dq.pop_front();
        }
    }
    while (!b.empty()) {
        ans += b.back();
        c.push_back(b.back());
        b.pop_back();
    }
    
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << c[i] << (i < n - 1 ? " " : "");
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
