#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int node;
    ll dis;
    state(int n, ll d): node(n), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> tran(26);
    auto id = [&](int x, int y) {
        return x * m + y;
    };
    int start = -1, end = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '@') start = id(i, j);
            else if (s[i][j] == '=') end = id(i, j);
            else if (s[i][j] >= 'A' && 'Z' >= s[i][j])
                tran[s[i][j] - 'A'].push_back(id(i, j));
        }
    }
    
    
    int V = n * m;
    vector<int> parent(V, -1);
    for (vector<int>& p: tran) {
        if (p.size() != 2) continue;
        parent[p[0]] = p[1];
        parent[p[1]] = p[0];
    }
    vector<ll> dis(V + 1, INF);
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    priority_queue<state> pq;
    dis[start] = 0;
    pq.push({start, dis[start]});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (w != dis[u]) continue;
        if (u == end) {
            cout << w;
            return 0;
        }
        int x = u / m, y = u % m;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (s[nx][ny] == '#') continue;
            int v = id(nx, ny);
            if (parent[v] != -1) v = parent[v];
            if (w + 1 < dis[v]) {
                dis[v] = w + 1;
                pq.push({v, dis[v]});
            }
        }
    }
    return 0;
}