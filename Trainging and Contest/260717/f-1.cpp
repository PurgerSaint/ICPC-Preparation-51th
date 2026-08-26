#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n; cin >> n;
    vector<ll> b(n * (n - 1) / 2);
    for (ll& t: b) cin >> t;
    if ((int)b.size() == 1) {
        cout << b[0] << " " << b[0];
        return;
    }
    sort(b.begin(), b.end());
    if (b.front() == b.back()) {
        for (int i = 0; i < n; i++)
            cout << b[0] << (i < n - 1 ? " " : "");
        return;
    }
    int len = n - 1, index = 0;
    vector<vector<int>> a(n);
    for (int i = 0; i < n - 1; i++) {
        ll mx = LLONG_MIN;
        // cout << "i:" << i << " ";
        for (int j = 0; j < len; j++) {
            // cout << b[index+j] << " ";
            if (j == 0) {
                mx = max(mx, b[index + j]);
                continue;
            } else if (mx != b[index + j]) {
                a[i + j + 1].push_back(b[index + j]);
                // cout << "To:" << (i+j+1) << " val:" << b[index+j] << "\n";
                continue;
            }
        }
        // cout << "\n";
        index += len;
        len--;
        a[i].push_back(mx);
    }
    /*cout << "=====\n";
    for (int i = 0; i < n; i++) {
        cout << "i:" << i + 1 << " ";
        for (int& t: a[i]) cout << t << " ";
        cout << "\n"; 
    }*/
    for (int i = 0; i < n; i++) {
        if (a[i].empty()) a[i].push_back(a[i - 1].back());
        else sort(range(a[i]));
        cout << a[i].back() << (i < n - 1 ? " " : "");
    }
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        if (tt) cout << "\n";
    }
    return 0;
}