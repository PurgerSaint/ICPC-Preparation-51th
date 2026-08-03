#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<int> b(n);
    for (int& t: b) cin >> t;
    sort(range(b));
    ll k = b.end() - upper_bound(range(b), 0);
    ll g = accumulate(range(b), 0LL) - (n - 1);
    return min(k, g);
}


int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}