#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        ll n, k; cin >> n >> k;
        if (k > n || ((n % 2) && !(k % 2))) {
            cout << "NO" << (tt ? "\n" : "");
            continue;
        }
        if (n == k) {
            cout << "YES" << "\n";
            for (int i = 1; i <= k; i++)
                cout << 1 << (i < k ? " " : (tt ? "\n" : ""));
            continue;
        }
        if (k == 1) {
            cout << "YES\n" << n << (tt ? "\n" : "");
            continue;
        }
        ll t = n - (k - 1);
        if (t > 0 && t % 2) {
            cout << "YES" << "\n";
            for (int i = 1; i < k; i++)
                cout << 1 << " ";
            cout << t << (tt ? "\n" : "");
            continue;
        }
        t = n - (2 * (k - 1));
        if (t > 0 && !(t % 2)) {
            cout << "YES" << "\n";
            for (int i = 1; i < k; i++)
                cout << 2 << " ";
            cout << t << (tt ? "\n" : "");
            continue;
        }
        cout << "NO" << (tt ? "\n" : "");
    }
    return 0;
}