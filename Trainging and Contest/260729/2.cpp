#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n, m; cin >> n >> m;
    set<int> a, b;
    int cnt_a = 0, cnt_b = 0, same = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.insert(t);
    }
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        b.insert(t);
    }
    for (const int& t: b)
        if (a.count(t))
            same++;
    cnt_a = a.size() - same;
    cnt_b = b.size() - same;
    // cout << "data: " << cnt_a << " " << cnt_b << " " << same << "\n";
    int ans = 0;
    if (cnt_a >= cnt_b) return cnt_b * 2 + (cnt_a > cnt_b) + (same > 0);
    return cnt_a * 2 + (same > 0);
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

