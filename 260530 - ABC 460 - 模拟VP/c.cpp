#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll& t: a) cin >> t;
    for (ll& t: b) cin >> t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    while (!a.empty() && !b.empty()) {
        while (!b.empty() && a.back() * 2 < b.back())
            b.pop_back();
        if (b.empty()) break;
        cnt++;
        a.pop_back();
        b.pop_back();
    }
    cout << cnt;
    return 0;
}