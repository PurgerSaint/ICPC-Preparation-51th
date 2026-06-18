#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int u; cin >> u;
            a[u].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int sz = a[i].size();
        cout << sz;
        if (!a[i].empty()) {
            cout << " ";
            for (int j = 0; j < sz; j++)
                cout << a[i][j] << (j != sz - 1 ? " " : "");
        }
        if (i < n) cout << "\n";
    }
    return 0;
}