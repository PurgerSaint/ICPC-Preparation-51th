#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    vector<int> b, len;
    for (int& t: a) {
        if (b.empty() || b.back() != t) {
            b.push_back(t);
            len.push_back(1);
        } else len.back()++;
    }
    int sz = b.size();
    if (sz == 1) return len[0] % 2 ? "NO" : "YES";
    vector<bool> vis(sz, 0);
    for (int i = 0; i < sz; i++) {
        if (vis[i]) continue;
        int l = len[i];
        int mx = i;
        for (int j = i + 1; j < sz; j++) {
            if (b[j] - b[j - 1] > k) break;
            if (vis[j]) continue;
            vis[j] = 1;
            mx = j;
            l += len[j];
        }
        if (l > 1) {
            if (len[mx] % 2 && l > len[mx]) return "YES";
            if (!(len[mx] % 2)) return "YES"; 
        }
    }
    return "NO";
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
