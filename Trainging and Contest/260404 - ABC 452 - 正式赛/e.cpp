#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
const int MOD = 998244353;

int main() {
    ios;
    int n, m; cin >> n >> m;
    ll sum = 0;
    vector<int> a(n), b(m);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            ll t = 1LL * a[i] * b[j] % MOD;
            t = t * ((i + 1) % (j + 1)) % MOD;
            sum = (sum + t) % MOD;
        }
    cout << sum;
    return 0;
}