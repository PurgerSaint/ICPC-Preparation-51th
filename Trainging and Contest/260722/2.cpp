#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    ll w, h, d; cin >> w >> h >> d;
    ll n; cin >> n;
    vector<ll> a, b;
    auto fd = [](const ll& t, vector<ll>& g) -> void {
        for (ll i = 1; i * i <= t; i++)
            if (t % i == 0) {
                g.push_back(i);
                g.push_back(t / i);
            }
        sort(range(g));
        g.erase(unique(range(g)), g.end());
    };
    fd(w, a); fd(h, b);
    for (ll& x: a) {
        if (n % x) continue;
        ll t = n / x;
        for (ll& y: b) {
            if (t % y) continue;
            ll g = t / y;
            if (d % g == 0) {
                cout << (x - 1) << " " << (y - 1) << " " << (g - 1);
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}