#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    ll n; cin >> n;
    if (n < 24) {
        cout << "NO";
        return;
    }
    //const ll k = sqrt(n) + 1;
    vector<ll> any;
    for (ll i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            any.push_back(i);
            any.push_back(n / i);
        }
    }
    if (any.empty()) {
        cout << "NO";
        return;
    }
    sort(range(any));
    any.erase(unique(range(any)), any.end());
    for (ll i = 0; i < (int)any.size(); i++) {
        ll& a = any[i];
        ll g = n / a;
        for (ll j = i + 1; j < (int)any.size(); j++) {
            ll& b = any[j], t = g / b;
            if (g % b == 0 && t != a && t != b && binary_search(range(any), t)) {
                cout << "YES" << "\n";
                cout << a << " " << b << " " << (g / b);
                return;
            }
        }
    }
    cout << "NO";
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