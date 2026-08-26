#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
vector<vector<pair<int, int>>> mp;

void dfs(int i, string vis, string& path) {
    path += to_string(i);
    for (pair<int, int>& p : mp[i]) {
        int& v = p.first;
        if (vis[v] == '0') {
            path += "->";
            vis[v] = '1';
            dfs(v, vis, path);
            return;
        }
    }
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    mp = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, val; cin >> u >> v >> val;
        mp[u].push_back({v, val});
    }

    for (vector<pair<int, int>>& v : mp)
        sort(v.begin(), v.end(), [](pair<int, int>& x, pair<int, int>& y){
            return x.second == y.second ? x.first < y.first : x.second > y.second;
        });
    
    int k; cin >> k;
    vector<int> root(k);
    for (int& t : root) cin >> t;

    for (int i = 0; i < k; i++) {
        string flag(n + 1, '0');
        string path = "";
        flag[root[i]] = '1';
        dfs(root[i], flag, path);
        cout << path << (i != k - 1 ? "\n" : "");
    }
    
    return 0;
}