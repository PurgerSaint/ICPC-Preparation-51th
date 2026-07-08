#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

bool solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    ll diff = 0, mx = a[0];
    vector<int> g;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            diff = max(diff, mx - a[i]);
            g.push_back(i);
        }
        mx = max(mx, a[i]);
    }
    if (diff == 0) return true;
    ll pre = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] >= pre) pre = a[i];
        else {
            if (a[i] + diff >= pre) {
                pre = a[i] + diff;
            } else return false;
        }
    }
    return true;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << (t ? "\n" : "");
    return 0;
}