#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int loc;
    char c;
    int cnt;
};

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<state> a;
    vector<vector<int>> loc(26);
    for (int i = 0; i < n; i++) {
        if (a.empty() || a.back().c != s[i])
            a.push_back({i, s[i], 1});
        else a.back().cnt++;
        loc[s[i] - 'a'].push_back(i);
    }
    sort(range(a), [](state& x, state& y){
        return x.cnt < y.cnt;
    });
    int cnt = a.size();
    for (vector<int>& p: loc) {
        if (p.empty()) continue;
        for (auto it = p.begin(); it + 1 != p.end(); it++)
            if (*(it + 1) - *it == 2)
                return cnt - 2;
    }
    for (auto& [lc, c, ct]: a) {
        if (lc == 0 || lc + ct == n) continue;
        if (ct == 1) cnt--;
        break;
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
