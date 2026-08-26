#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<pair<int, ll>>> mp;
vector<int> sz;
ll ans = 0;
int n;
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto& [v, w]: mp[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            ans += w * (n - 2 * min(sz[v], n - sz[v]));
        }
    }
}


int main() {
    ios;
    cin >> n;
    mp = vector<vector<pair<int, ll>>>(n + 1);
    sz = vector<int>(n + 1);
    vector<bool> f(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w}); 

    }
    dfs(1, 1);
    cout << ans;
    return 0;
}