#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    ll x; cin >> x;
    if (x == 0) {
        cout << "0 -1 -1";
        return 0;
    }
    int mx = 0, mn = 64, cnt = 0;
    for (int i = 0; i < 62; i++) {
        if ((x >> i) & 1) {
            cnt++;
            mx = max(mx, i);
            mn = min(mn, i);
        }
    }
    cout << cnt << " ";
    if (cnt == 0) cout << "-1 -1";
    else cout << mn << " " << mx;
    return 0;
}