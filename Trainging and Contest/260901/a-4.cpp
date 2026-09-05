#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    while (true) {
        int n; ll d; cin >> n >> d;
        if (n == 0 && d == 0) break;
        vector<ll> a(n);
        for (ll& t: a) cin >> t;
        int cnt = 0, i = 0;
        while (i < n) {
            ll mx = a[i] + 2 * d;
            cnt++;
            while (i < n && a[i] <= mx) i++;
        }
        cout << cnt << "\n";
    }
    return 0;
}