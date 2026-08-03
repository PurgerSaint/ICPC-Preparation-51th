#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
const int MOD = 676767677;
#define mod(t) (t % MOD + MOD) % MOD

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int x, y; cin >> x >> y;
        int s = x - y;
        ll ans = 0;
        for (int i = 1; i <= abs(s); i++)
            if (s % i == 0)
                ans++;
        if (s == 0) ans = 1;
        cout << ans << "\n";

        vector<int> a;
        for (int i = 0; i < x; i++) a.push_back(1);
        for (int i = 0; i < y; i++) a.push_back(-1);
        for (int i = 0; i < x + y; i++)
            cout << a[i] << (i < x + y - 1 ? " " : (tt ? "\n" : ""));
    }
    return 0;
}