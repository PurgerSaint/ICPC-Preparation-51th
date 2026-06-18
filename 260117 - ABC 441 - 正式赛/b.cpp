#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
set<char> s, t;

string solve() {
    string w; cin >> w;
    set<char> a, b, c;
    for (char k: w) {
        a.insert(k);
        if (s.count(k)) b.insert(k);
        if (t.count(k)) c.insert(k);
    }
    if (b.size() == c.size()) return "Unknown";
    if (b.size() == a.size()) return "Takahashi";
    if (c.size() == a.size()) return "Aoki";
    return "Unknown";
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    string s1; cin >> s1;
    for (char c: s1)
        s.insert(c);
    string s2; cin >> s2;
    for (char c: s2)
        t.insert(c);
    int q; cin >> q;
    while (q--) {
        cout << solve() << (q != 0 ? "\n" : "");
    }
    return 0;
}