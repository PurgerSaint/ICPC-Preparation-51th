#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()



int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> mp(n);
    for (string& s: mp) cin >> s;
    
    int w = m + 1, v = (n + 1) * (m + 1);
    auto id = [&](int x, int y) {
        return x * w + y;
    };
    vector<vector<pair<int, int>>> graph(v);
    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lu = id(i, j), ld = id(i + 1, j);
            int ru = id(i, j + 1), rd = id(i + 1, j + 1);

            addEdge(lu, rd, mp[i][j] != '\\');
            addEdge(ru, ld, mp[i][j] != '/');
        }
    }
    const int INF = 1e9;
    vector<int> dis(v, INF);
    deque<int> q;
    int start = id(0, 0), target = id(n, m);
    dis[start] = 0;
    q.push_front(start);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto& [v, w]: graph[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    if (dis[target] == INF) cout << "NO SOLUTION";
    else cout << dis[target];
    return 0;
}