#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char, int>> b;
    for (char c: s) {
        if (b.empty() || b.back().first != c) b.push_back({c, 1});
        else b.back().second++;
    }
    int x = 0, y = 0;
    int cnt1 = 0, cnt0 = 0;
    for (auto& [c, cnt]: b) {
        if (cnt == 1) {
            c == '1' ? cnt1++ : cnt0++;
            continue;
        }
        int& t = c == '1' ? x : y;
        t += cnt - 1;
        c == '1' ? cnt1++ : cnt0++;
    }
    if (abs((x + cnt1) - (y + cnt0)) > 2) return -1;
    return 2 * min(x, y) + abs(x - y) * 2 - (abs(x - y) > 0);
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
