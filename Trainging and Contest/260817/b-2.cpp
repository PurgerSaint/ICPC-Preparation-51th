#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll solve() {
    int m, n; cin >> m >> n;
    map<ll, vector<ll>> mp;
    for (int i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        if (u == v) continue;
        mp[u].push_back(v);
    }
    ll last = 0, cnt = n;
    // set<ll> st;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        vector<ll>& gk = (*it).second;
        const ll& i = (*it).first;
        if (gk.empty()) continue;
        sort(range(gk));
        ll start = max(last, i);
        for (ll& t: gk) {
            if (t > start) {
                start++;
                cnt--;
            }
        }
        // for (ll i = start + 1; i < last; i++)
            // st.insert(i);
        // cout << i << " " << start << " ";
        last = start;
        // cout << start << "\n";
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