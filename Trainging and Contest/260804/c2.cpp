#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) return 0;
    if (n < 3) return -1;
    vector<int> a1, b1, a2, b2;
    for (int i = 1; i <= n; i++) {
        vector<int>& a = i % 2 ? a1 : a2;
        vector<int>& b = i % 2 ? b1 : b2;
        if (s[i - 1] == '1') a.push_back(i);
        if (t[i - 1] == '1') b.push_back(i);
    }
    ll ans = 0;
    for (int k = 1; k <= 2; k++) {
        vector<int>& a = k % 2 ? a1 : a2;
        vector<int>& b = k % 2 ? b1 : b2;
        if (a.size() != b.size()) return -1;
        for (int i = 0; i < (int)a.size(); i++)
            ans += abs(a[i] - b[i]);
    }
    return ans / 2;
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
