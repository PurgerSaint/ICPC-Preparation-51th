#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        st.insert({u, v});
    }
    bool f = 1;
    for (int i = 1; i < n; i++) {
        if (!st.count({i, i + 1}))
            f = 0;
    }
    cout << (f ? "Yes" : "No");
    return 0;
}
