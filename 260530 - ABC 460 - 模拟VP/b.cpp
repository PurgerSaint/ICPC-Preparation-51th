#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll t1 = abs(x1 - x2), t2 = abs(y1 - y2);
        ll dic = t1 * t1 + t2 * t2;
        if (dic <= ((r1 + r2) * (r1 + r2)) && dic >= abs(r1 - r2) * abs(r1 - r2)) cout << "Yes";
        else cout << "No";
        cout << (t ? "\n" : "");
    }
    return 0;
}