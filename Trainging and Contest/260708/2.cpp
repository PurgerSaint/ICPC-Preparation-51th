#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
        int ans = 0;
        if (n <= 3) ans = 1;
        else if (x1 < x2) {
            int a = x2 - x1, b = x1 - 1 + 1 + n - x2;
            ans = min(a, b) + k;
        } else if (x1 > x2) {
            int a = x1 - x2, b = n - x1 + 1 + x2 - 1;
            ans = min(a, b) + k;
        }
        cout << ans << (tt ? "\n" : "");
    }
    return 0;
}

/*
int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
        if (n <= 3) cout << 1;
        else cout << min(abs(x1 - x2), n - abs(x1 - x2)) + k;
    }
    return 0;
}*/