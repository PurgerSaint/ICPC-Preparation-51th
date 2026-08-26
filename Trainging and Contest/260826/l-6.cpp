#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<vector<int>> mp;
vector<int> mx;

int main() {
    ios;
    int n, m; cin >> n >> m;
    mp = vector<vector<int>>(n + 1);
    mx = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        if (mx[i]) continue;
        mx[i] = i;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v: mp[u]) {
                if (!mx[v]) {
                    mx[v] = i;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << mx[i] << (i < n ? " " : "");
    return 0;
}