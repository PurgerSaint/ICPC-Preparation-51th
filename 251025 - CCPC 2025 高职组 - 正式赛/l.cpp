#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (pair<ll, ll>& p : a) cin >> p.first >> p.second;
    ll& x1 = a[0].first, y1 = a[0].second;
    ll& x2 = a[1].first, y2 = a[1].second;
    for (int i = 2; i < n; i++) {
        ll& x3 = a[i].first, y3 = a[i].second;
        if ((x1 - x2) * (y3 - y1) - (y1 - y2) * (x3 - x1) != 0) {
            cout << "YES";
            return 0;
        }
    }
    // cout << cntx.size() << " " << cnty.size() << (a ? "a" : "") << " " << (b ? "b" : "") << "\n";
    cout << "NO";
    return 0;
}