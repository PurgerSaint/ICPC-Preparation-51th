#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    vector<pair<int, int>> b;
    map<int, int> mp;
    int sum = 0;
    for (int& t: a) {
        sum += t;
        if (b.empty() || !mp.count(t)) {
            mp[t] = b.size();
            b.push_back({t, 1});
        } else b[mp[t]].second++;
    }
    sort(range(b), [](auto& x, auto& y){ return x.second < y.second; });
    int other = n - b.back().second;
    int use = min(other + 2, b.back().second);
    return sum - b.back().first * (b.back().second - use);
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
