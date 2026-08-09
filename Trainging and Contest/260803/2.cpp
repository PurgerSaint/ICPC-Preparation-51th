#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    map<int, vector<int>> zb;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        zb[b[i]].push_back(i);
    }
    vector<int> ans(n);
    int g = 1;
    for (auto& [t, k]: zb) {
        int cnt = k.size();
        if (t > cnt || cnt % t != 0) {
            cout << -1;
            return;
        }
        for (int j = 1; j <= cnt; j++) {
            ans[k[j - 1]] = g;
            if (j % t == 0) g++;
        }
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << (it + 1 != ans.end() ? " " : "");
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
