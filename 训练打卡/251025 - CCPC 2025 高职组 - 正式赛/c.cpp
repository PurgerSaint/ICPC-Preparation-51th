#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n; ll t; cin >> n >> t;
    ll t1 = t, x = 0;
    for (int i = 0; i < n; i++) {
        ll ti, ki; cin >> ti >> ki;
        if (ti <= t1) {
            x += ti;
            t1 -= ti;
        } else {
            if (t1 > 0) {
                x += t1;
                ti -= t1;
                t1 = -1;
            }
            for (int j = 1; j <= ti; j++) {
                x++;
                if (x <= t) break;
                if ((x - t) > ki) break;
            }
        }
        // cout << x << " " << t1 << "\n";
    }
    cout << x;
    return 0;
}