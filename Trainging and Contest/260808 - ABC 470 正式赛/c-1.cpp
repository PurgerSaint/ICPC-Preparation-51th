#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0, diff = 0;
    for (int& t: a) {
        cin >> t;
        mx = max(mx, t);
    }
    for (int& t: a) {
        if (t == mx) continue;
        diff = max(diff, mx - t);
    }
    return diff + 1;
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
