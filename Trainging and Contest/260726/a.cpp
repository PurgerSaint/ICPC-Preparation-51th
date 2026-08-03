#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll mx = 0, nx = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i - 1];
        ll& t = a[i - 1];
        if (i % 2) nx = min(t, nx);
        else mx = max(mx, t);
    }
    if (n % 2) return false;
    // for (int i = 0; i < n - 1; i++)
    //     if (abs(a[i] - a[i + 1]) <= 1)
    //        return false;
    return nx > mx + 1;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO");
        cout << (tt ? "\n" : "");
    }
    return 0;
}
