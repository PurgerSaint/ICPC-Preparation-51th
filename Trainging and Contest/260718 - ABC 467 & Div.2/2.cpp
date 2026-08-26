#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int k, n; ll m; cin >> n >> k >> m;
    if (k > m) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << (!(i % k) ? m - k + 1 : 1) << (i < n - 1 ? " " : "");
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