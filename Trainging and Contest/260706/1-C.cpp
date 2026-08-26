#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int cnt = 1;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            if (i > 0 && a[i] != a[i - 1]) {
                cnt++;
                a[i].second = 0;
            }
            a[i].second++;
        }
        int mx = n;
        for (auto& p: a) mx = min(mx, p.second);
        bool flag = false;
        if (k >= n && (k - n) % cnt == 0) {
            flag = true;
        } else if (k < n && ((n - k) / cnt <= mx && (n - k) / cnt > 0)) {
            flag = true;
        }
        cout << (flag ? "YES" : "NO") << (tt ? "\n" : "");
    }
    return 0;
}