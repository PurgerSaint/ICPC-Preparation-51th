#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int k = 1;
        for (int i = 0; i < n; i++) {
            cout << (k * (k + 2));
            k += 2;
            if (i < n - 1) cout << " ";
            else if (tt) cout << "\n";
        }
    }
    return 0;
}