#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> has(m + 1);
    vector<set<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int t; cin >> t;
            has[t].insert(i);
            a[i].insert(t);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (has[i].empty()) return "No";
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool f = 1;
        for (const int& t: a[i]) {
            if (has[t].size() == 1) {
                f = 0;
                break;
            }
        }
        if (!f) continue;
        cnt++;
    }
    return cnt >= 2 ? "YES" : "NO";
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
