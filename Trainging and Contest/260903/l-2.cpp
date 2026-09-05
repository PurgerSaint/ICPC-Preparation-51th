#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<pair<int, int>> a;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a.emplace_back(l, r);
        mx = max(mx, max(l, r));
    }
    vector<bool> vis(mx + 1, 1);
    vis[1] = vis[0] = 0;
    for (int i = 3; i <= mx; i += 2) {
        if (vis[i]) {
            for (int j = 3; j * i <= mx; j++)
                vis[j * i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        auto& [l, r] = a[i];
        if (l + 2 == r && l % 2 && r % 2 && vis[l] && vis[r]) cout << "Y";
        else cout << "N";
        if (i < n - 1) cout << "\n";
    }
    return 0;
}
