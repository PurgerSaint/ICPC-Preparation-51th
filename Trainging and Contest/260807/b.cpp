#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n; cin >> n;
    vector<int> b, len;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (b.empty() || b.back() != t) {
            b.push_back(t);
            len.push_back(1);
        } else len.back()++;
    }
    int sz = b.size();
    if (sz == n) return n;
    if (sz == 1) return 1;
    int cnt = 0, mn = n, mx = 0;
    for (int i = 0; i < sz; i++)
        if (len[i] >= 2) {
            n -= len[i] - 2;
            len[i] = 2;
            cnt++;
            mn = min(mn, i);
            mx = max(mx, i);
        }
    for (int i = 0; i < sz - 1; i++)
        if (len[i] == 2 && len[i + 1] == 2)
            return n - cnt + 2;
    if (sz) {
        if (mx == sz - 2) return n - cnt + 1;
        if (mx < sz - 2 && b[mx] != b[mx + 2]) return n - cnt + 1;
        if (mn == 1) return n - cnt + 1;
        if (mn > 1 && b[mn] != b[mn - 2]) return n - cnt + 1;
    }
    for (int i = 0; i < sz; i++) {
        if (len[i] == 2 && ((i > 1 && b[i] != b[i - 2]) || (i < sz - 2 && b[i] != b[i + 2]))) {
            return n - cnt + 1;
        }
    }
    return n - cnt;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}
