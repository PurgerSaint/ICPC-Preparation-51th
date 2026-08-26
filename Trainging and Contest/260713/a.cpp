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
        for (int i = 2; i <= n; i++)
            cout << i << " ";
        cout << 1 << (tt ? "\n" : "");
    }
    return 0;
}