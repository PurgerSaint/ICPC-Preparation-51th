#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int loc;
    char c;
    int cnt;
};
bool solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) return 1;
    if (n < 3) return 0;
    vector<int> a1, b1, a2, b2;
    for (int i = 1; i <= n; i++) {
        vector<int>& a = i % 2 ? a1 : a2;
        vector<int>& b = i % 2 ? b1 : b2;
        if (s[i - 1] == '1') a.push_back(i);
        if (t[i - 1] == '1') b.push_back(i);
    }
    return a1.size() == b1.size() && a2.size() == b2.size();
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
       cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}
