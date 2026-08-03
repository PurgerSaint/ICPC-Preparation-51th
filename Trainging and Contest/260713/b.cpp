#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << -1;
        return;
    }
    if (n == 1) {
        cout << 1;
        return;
    }
    vector<ll> a(n);
    a[0] = 1;
    a[1] = 2;
    ll sum = 3;
    for (int i = 2; i < n; i++) {
        a[i] = sum;
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << (i < n - 1 ? " " : "");
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        if (tt) cout << "\n";
    }
    return 0;
}