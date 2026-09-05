#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

void solve() {
    string s; cin >> s;
    int n = s.length();
    for (int i = 0; i + 1 < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            cout << s[i] << s[i + 1];
            return;
        }
        if (i + 2 < n && s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
            cout << s[i] << s[i + 1] << s[i + 2];
            return;
        }
        if (i + 3 < n && s[i] == s[i + 3] && s[i + 1] == s[i + 2] && s[i] != s[i + 1]) {
            for (int j = 0; j < 4; j++) cout << s[i + j];
            return;
        }
    }
    cout << -1;
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

// aba