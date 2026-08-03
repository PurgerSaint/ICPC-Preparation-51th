#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<ll>> cnt;
        for (int i = 0; i < n; i++) {
            ll t; cin >> t;
            if (cnt.empty() || (cnt.back().back() < 0 && t > 0) || (cnt.back().back() > 0 && t < 0)) {
                cnt.push_back({t});
            } else cnt.back().push_back(t);
        }
        vector<ll> kt;
        for (vector<ll>& p: cnt) {
            sort(p.begin(), p.end(), greater<ll>());
            kt.push_back(p[0]);
        }
        cout << accumulate(kt.begin(), kt.end(), 0LL) << (tt ? "\n" : "");
    }
    return 0;
}