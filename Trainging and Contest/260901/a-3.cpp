#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    while (true) {
        int n; cin >> n;
        if (!n) break;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            if (t == 1) t = 14;
            else if (t == 2) t = 15;
            mx = max(mx, t);
        }
        if (mx == 15) cout << 2;
        else if (mx == 14) cout << 1;
        else cout << mx;
        cout << "\n";
    }
    return 0;
}