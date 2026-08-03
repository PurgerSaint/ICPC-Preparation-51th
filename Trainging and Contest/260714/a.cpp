#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, mx = 0;
    for (char c: s) {
        if (c == '#') {
            cnt++;
            mx = max(cnt, mx);
        } else cnt = 0;
    }
    return mx / 2 + (mx % 2);
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0;
}