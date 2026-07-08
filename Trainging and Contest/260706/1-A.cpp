#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            if (t == 2) a++;
            else if (t > 2) b++;
        }
        cout << (b > 0 || a > 1 ? "YES" : "NO") << (tt ? "\n" : "");
    }
    return 0;
}