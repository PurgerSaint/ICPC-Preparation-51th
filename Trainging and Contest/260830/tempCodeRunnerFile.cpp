#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    ll x; cin >> x;
    vector<ll> p;
    ll g = 1;
    while (g <= x) {
        p.push_back(g);
        g *= 2;
    }
    int mx = 0, mn = 64, cnt = 0;
    while (x > 0) {
        auto it = lower_bound(range(p), x);
        cnt++;
        if (it == p.begin()) {
            mn = min(mn, 0);
            break;
        }
        it--;
        mx = max(mx, static_cast<int>(it - p.begin()));
        mn = min(mn, static_cast<int>(it - p.begin()));
        x -= *it;
    }
    cout << cnt << " ";
    if (mx == 0) cout << "-1 -1";
    else cout << mn << " " << mx;
    return 0;
}