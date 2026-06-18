#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

ll c(ll x) {
    if (x < 3) return 0;
    return x * (x - 1) * (x - 2) / 6;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<set<int>> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cnt[a].insert(b);
        cnt[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        int sz = (n - 1) - cnt[i].size();
        cout << c(sz) << (i == n ? "" : " ");
    }
    return 0;
}