#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<string> start = {"110", "011", "001", "100"};
    ll ans = 0;
    for (string st: start) {
        string t = st;
        while ((int)t.length() < n) {
            char n1 = *(t.rbegin() + 1), n2 = *(t.rbegin());
            if (n1 == '1' && n2 == '1') t += '0';
            else if (n1 == '0' && n2 == '1') t += '1';
            else if (n1 == '0' && n2 == '0') t += '1';
            else if (n1 == '1' && n2 == '0') t += '0';
        }
        bool f = 1;
        for (int i = 0; i < n; i++)
            if (s[i] != '?' && s[i] != t[i]) {
                f = 0;
                break;
            }
        if (f) ans++;
    }
    return ans;
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
