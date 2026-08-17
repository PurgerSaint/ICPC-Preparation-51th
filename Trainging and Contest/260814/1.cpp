#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

string solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s[0] == ')' || t[0] == ')' || t[n - 1] == '(' || s[n - 1] == '(') return "NO";
    int l = 0;
    for (int i = 0; i < n; i++)
        l += (s[i] == '(') + (t[i] == '(');
    if (l != n) return "NO";
    int calA = 0, calB = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            if (s[i] == '(') calA++, calB++;
            else calA--, calB--;
        } else if (calA > calB) {
            calA--, calB++;
        } else {
            calA++, calB--;
        }
        if (calA < 0 || calB < 0)
            return "NO";
    }
    return "YES";
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