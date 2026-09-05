#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

void solve() {
    ll n; cin >> n;
    ll g = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            g = n / i;
            break;
        }
    }
    cout << g << " " << n - g;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}