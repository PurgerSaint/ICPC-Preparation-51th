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
        vector<int> a(n);
        // cout << "1-1\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int re = 0, s = -1, mn = min_element(range(a)) - a.begin();
        // cout << "1-2\n";
        s = a[0];
        for (int i = 1; i < mn; i++) {
            // cout << "1-3" << i << "\n";
            if (a[i] < s) s = a[i];
            else re += a[i] - s;
        }
        s = a[n - 1];
        for (int i = n - 2; i > mn; i--) {
            // cout << "1-4" << i << "\n";
            if (a[i] < s) s = a[i];
            else re += a[i] - s;
        }
        cout << re << "\n";
    }
    return 0;
}