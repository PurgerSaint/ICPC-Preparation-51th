#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n; cin >> n;
    vector<pair<ll, vector<int>>> loc;
    map<ll, int> st;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (!st.count(t)) {
            st[t] = loc.size();
            loc.push_back({t, {i}});
        } else loc[st[t]].second.push_back(i);
    }
    sort(range(loc), [](auto& a, auto& b){ return a.first < b.first; });
    if (loc[0].first > 0) {
        cout << -1;
        return;
    }
    vector<ll> ans(n);
    ll sum = 0, g = 1;
    for (auto it = loc.begin(); it != loc.end(); it++) {
        auto& [num, p] = *it;
        if (it + 1 != loc.end()) {
            auto& [next_num, next_p] = *(it + 1);
            ll less = next_num - sum;
            if (less % (int)p.size() || less / (int)p.size() < g) {
                cout << -1;
                return;
            }
            g = less / (int)p.size();
            sum = next_num; 
        }
        for (int& i: p) ans[i] = g;
        g++;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << (i < n - 1 ? " " : "");
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}
