#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n, k; cin >> n >> k;
    if (k == n * n - 1) {
        cout << "NO";
        return;
    }
    vector<string> ans(n, string(n, 'D'));
    for (int i = k / n + (k % n > 0); i < n; i++)
        ans[n - 1][i] = 'U';
    if (k < n * n && k % n) {
        if (k % n == n - 1) ans[0][k / n] = 'R';
        else ans[(n - 1) - (k % n)][k / n] = 'U';
    }
    cout << "YES" << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << (it + 1 != ans.end() ? "\n" : "");
    }
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
