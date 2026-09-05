#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m
#define range(a) a.begin(), a.end()

ll solve() {
    ll m, n; cin >> m >> n;
    map<ll, vector<ll>> mp;
    for (int i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        mp[u].push_back(v);
    } 
    for (auto& [_, p]: mp)
        sort(range(p));
    ll cnt = n;
    multiset<ll> st;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto& [left, p] = *it;
        for (ll& t: p) st.insert(t);
        ll end = (it == prev(mp.end()) ? n : (*next(it)).first);
        for (ll pos = left; pos < end; pos++) {
            while (!st.empty() && *st.begin() <= pos)
                st.erase(st.begin());
            if (st.empty()) break;
            cnt--;
            st.erase(st.begin());
        }
    }
    return cnt;
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