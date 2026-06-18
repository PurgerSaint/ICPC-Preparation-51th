#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
vector<vector<pair<int, int>>> mp;
vector<int> ed;
unordered_map<int, vector<int>> hsh;

void dfs(int i, int mx) {
    // if (mx == INT_MAX) return;
    if (mp[i].empty()) {
        if (!hsh.count(mx)) {
            ed.push_back(mx);
        }
        hsh[mx].push_back(i);
        return;
    }
    for (pair<int, int>& v : mp[i]) {
        dfs(v.first, min(mx, v.second));
    }
}

int main() {
    ios;
    int n; cin >> n;
    mp = vector<vector<pair<int, int>>>(n);
    for (int i = 1; i < n; i++) {
        int v, val; cin >> v >> val;
        mp[min(i, v)].push_back({max(i, v), val});
    }

    dfs(0, INT_MAX);

    int sz = ed.size();
    sort(ed.begin(), ed.end(), [](int& x, int& y){
        return x > y;
    });
    int& mx = ed.front();
    vector<int>& ans = hsh[mx];
    cout << mx << "\n";
    sz = ans.size();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < sz; i++)
        cout << ans[i] << (i != sz - 1 ? " " : "");
    return 0;
}