#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int n, k;
vector<vector<int>> ans;
vector<int> path;
void dfs(int i, int s, vector<int> path) {
    if (s < 0) return;
    if (i == n) {
        if (s % n == 0) {
            path[n] = s / n;
            ans.push_back(path);
        }
        return;
    }
    for (int g = 0; g <= k; g++) {
        if (g * i > s) break;
        path[i] = g;
        dfs(i + 1, s - i * g, path);
        path[i] = 0;
    }
}

int main() {
    ios;
    cin >> n >> k;
    path = vector<int>(n + 1, 0);
    dfs(1, k, path);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        vector<int>& p = *it;
        for (int i = 1; i <= n; i++)
            cout << p[i] << (i < n ? " " : "");
        if (it + 1 != ans.end()) cout << "\n";
    }
    return 0;
}