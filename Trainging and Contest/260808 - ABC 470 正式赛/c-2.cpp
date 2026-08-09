#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> b(k);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '1') {
            x++;
            b[i % k].push_back(i);
        } else y++;
    }
    if (x == 0) return "YES";
    if (y % 1 && n < k + 1) return "NO";
    for (vector<int>& p: b)
        if ((int)p.size() % 2)
            return "NO";
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
