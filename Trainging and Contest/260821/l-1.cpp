#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int n;
vector<vector<int>> mp;
int dfs(int i) {
    if (i > n) return 0;
    if (mp[i].empty()) return 1;
    int ans = 0;
    for (int& node: mp[i])
        ans = max(ans, 1 + dfs(node));
    return ans;
}

int main() {
    ios;
    cin >> n;
    mp = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        if (u) mp[i].push_back(u);
        if (v) mp[i].push_back(v);
    }
    cout << dfs(1);
    return 0;
}