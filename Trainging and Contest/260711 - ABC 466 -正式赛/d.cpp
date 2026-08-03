#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> op(m);
    for (pair<int, int>& p: op)
        cin >> p.first >> p.second;
    vector<bool> r(n + 1, 0), c(n + 1, 0); 
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--) {
        pair<int, int>& p = op[i];
        if (!r[p.first] && !c[p.second]) cnt++;
        r[p.first] = 1;
        c[p.second] = 1;
    }
    cout << cnt;
    return 0;
}