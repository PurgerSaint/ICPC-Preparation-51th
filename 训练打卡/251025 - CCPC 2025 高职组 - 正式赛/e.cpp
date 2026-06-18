#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> cost(m);
    for (pair<ll, ll>& t : cost) cin >> t.first >> t.second;
    for (int i = 0; i < n; i++) {
        ll w, p, q; cin >> w >> p >> q;
        double x = w * (p / (double)q);
        for (pair<ll, ll>& t : cost)
            if (x >= t.first) {
                x = min(x, x - (x  / t.first) * t.second);
            }
        ll cnt = 10;
        while (x / 10 == 0)
    }
    return 0;
}

