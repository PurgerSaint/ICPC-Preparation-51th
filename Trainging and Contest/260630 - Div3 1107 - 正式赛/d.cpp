#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

string solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    ll sum = 0, flag = 1;
    for (int i = 0; i < n; i++) {
        ll d = a[i] - b[i];
        sum += d;
        if (sum > 0) {
            flag = 0;
            break;
        }
    }
    return (flag ? "Yes" : "No");
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t ? "\n" : "");
    return 0;
}