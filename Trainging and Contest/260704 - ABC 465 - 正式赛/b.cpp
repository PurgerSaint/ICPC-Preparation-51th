#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int x, y, l, r, a, b; cin >> x >> y >> l >> r >> a >> b;
    if (b < l || a > r) {
        cout << ((b - a) * y);
    } else if (l <= a && b <= r) {
        cout << ((b - a) * x);
    } else if (a <= l && r <= b) {
        cout << ((l - a) * y + (r - l) * x + (b - r) * y);
    } else if (a <= l && (l <= b && b <= r)) {
        cout << ((l - a) * y + (b - l) * x);
    } else if ((l <= a && a <= r) && r <= b) {
        cout << ((r - a) * x + (b - r) * y);
    }
    return 0;
}