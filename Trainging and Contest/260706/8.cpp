#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n, t; cin >> n >> t;
    vector<vector<int>> mp(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a; cin >> a;
        mp[i].push_back(i + a);
    }
    queue<int> q;
    vector<bool> vis(n + 1, 0);
    bool flag = false;

    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) {
            flag = 1;
            break;
        }
        if (vis[u]) continue;
        vis[u] = 1;
        for (int& v: mp[u]) {
            if (!vis[v]) {
                q.push(v);
            }
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}