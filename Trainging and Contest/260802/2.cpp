#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    if (n <= m) return false;
    sort(range(a));
    sort(range(b));
    if (n < 2 * m) return 0;
    for (int i = 0; i < m; i++)
        if (!(a[i] < b[i] && b[i] < a[n - m + i]))
            return 0;
    return 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}
