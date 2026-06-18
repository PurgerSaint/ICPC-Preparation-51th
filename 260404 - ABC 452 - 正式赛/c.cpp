#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<pair<int, int>> loc(n);
    unordered_map<int, map<int, set<char>>> hash;
    for (pair<int, int>& p: loc) {
        cin >> p.first >> p.second;
        p.second--;
        hash[p.first][p.second] = {};
    }
    int m; cin >> m;
    vector<string> st(m);
    for (string& s: st) {
        cin >> s;
        if (hash.count(s.length())) {
            for (auto& t: hash[s.length()]) {
                t.second.insert(s[t.first]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        string& s = st[i];
        if (s.length() != n) {
            cout << "No";
            if (i != m - 1) cout << "\n";
            continue;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            pair<int, int>& t = loc[i];
            if (!hash[t.first][t.second].count(s[i])) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << (i != m - 1 ? "\n" : "");
    }
    return 0;
}