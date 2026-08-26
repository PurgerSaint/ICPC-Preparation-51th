#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

ll ls(ll x) {
    if (x <= 0) return 0;
    ll r = static_cast<ll>(sqrtl((long double)x));
    while (r > x / r) r--;
    while ((r + 1) <= x / (r + 1)) r++;
    return r;
}

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    ll mx = 1;
    for (ll& t: a) {
        cin >> t;
        mx = max(mx, t);
    }
    ll limit = ls(mx);
    vector<bool> vis(limit + 1, 1);
    if (limit >= 0) vis[0] = 0;
    if (limit >= 1) vis[1] = 0;
    for (ll i = 2; i <= limit / i; i++) {
        if (vis[i]) {
            for (ll j = i * i; j <= limit; j += i)
                vis[j] = 0;
        }
    }
    vector<ll> st;
    for (ll i = 2; i <= limit; i++)
        if (vis[i])
            st.push_back(i * i);
    for (int i = 0; i < n; i++) {
        cout << (binary_search(st.begin(), st.end(), a[i]) ? "YES" : "NO") << (i < n - 1 ? "\n" : "");
    }
    return 0;
}