#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int h, w, q; cin >> h >> w >> q;
    while (q--) {
        int c, r; cin >> c >> r;
        if (c == 1) {
            cout << w * r;
            h -= r;
        } else {
            cout << h * r;
            w -= r;
        }
        if (q != 0) cout << "\n";
    }
    return 0;
}