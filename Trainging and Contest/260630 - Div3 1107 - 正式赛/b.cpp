#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        
        ll y = 1;
        while (x > 0) {
            y *= 10;
            x /= 10;
        }

        cout << (y + 1) << (t ? "\n" : "");
    }
    return 0;
}