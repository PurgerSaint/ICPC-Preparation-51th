#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    string s, t; cin >> s >> t;
    map<char, int> a, b;
    for (char c: s) a[c]++;
    for (char c: t) b[c]++;
    for (auto& [c, cnt]: a) {
        if (!b.count(c) || cnt > b[c]) return "Impossible";
        b[c] -= cnt;
    }
    vector<string> part;
    for (char c: s) {
        if (part.empty() || part.back()[0] < c) part.push_back("");
        part.back() += c;
    }
    string ans = "";
    int use = 0;
    for (auto& [c, cnt]: b) {
        if (use < (int)part.size() && part[use][0] <= c) {
            // cout << part[use] << "\n";
            ans += part[use++];
        }
        string p = "";
        for (int i = 0; i < cnt; i++) p += c;
        ans += p;
        ans += string(c, cnt);
    }
    for (int i = use; i < (int)part.size(); i++)
        ans += part[i];
    return ans;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
