#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    string s; cin >> s;
    string ans = "";
    int a = 0, b = 0;
    for (char c: s) {
        if (c == '1' && a == 0) {
            a = 1;
            continue;
        }
        if (c == '0' && b == 0) {
            b = 1;
            continue;
        }
        ans += c;
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
