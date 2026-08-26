#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = count(range(s), '0');
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        char c = i < cnt ? '0' : '1';
        if (s[i] != c)
            ans.push_back(i + 1);
    }
    if (ans.empty()) {
        cout << "Bob";
        return;
    }
    cout << "Alice" << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << (i + 1 < (int)ans.size() ? " " : "");
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}