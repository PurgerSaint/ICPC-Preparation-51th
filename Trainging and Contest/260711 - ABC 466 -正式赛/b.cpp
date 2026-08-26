#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m + 1);
    for (int i = 0; i < n; i++) {
        int c, s; cin >> c >> s;
        a[c].push_back(s);
    }
    for (int i = 1; i <= m; i++) {
        vector<int>& p = a[i];
        if (p.empty()) cout << -1;
        else {
            sort(p.begin(), p.end());
            cout << p.back();
        }
        if (i < m) cout << " ";
    }
    
    return 0;
}