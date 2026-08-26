#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int n, m;
vector<set<int>> mp;
vector<int> res;

bool dfs(int u, int end, set<int> path) {
    if (u == end) {

    }
    if (mp[u].empty()) {
        int step = *max_element(path.begin(), path.end());

    }
}

int main() {
    ios;
    cin >> n >> m;
    mp = vector<set<int>>(n + 1);
    res = vector<int>(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].insert(v);
    }
    if (mp[1].empty()) {
        cout << 0 << "\n";
        for (int i = 2; i <= n; i++) {
            cout << "-1";
            if (i != n) cout << "\n";
        }
    }

    for (int i = 1; i <= n; i++) {
        
    }

    return 0;
}