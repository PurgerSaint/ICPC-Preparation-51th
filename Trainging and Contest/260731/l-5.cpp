#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int x, y;
    ll dis;
    state(int x1, int y1, ll d): x(x1), y(y1), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

int main() {
    ios;
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<pair<int, int>> d(a), k(b);
    for (auto& [x, y]: d) cin >> x >> y;
    for (auto& [x, y]: k) cin >> x >> y;
    vector<vector<ll>> dis(n + 1, vector<ll>(m + 1, INF));
    priority_queue<state> pq;
    for (auto& [x, y]: d) {
        dis[x][y] = 0;
        pq.push({x, y, 0});
    }
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto [x, y, w] = pq.top(); pq.pop();
        if (dis[x][y] != w) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (w + 1 < dis[nx][ny]) {
                dis[nx][ny] = w + 1;
                pq.push({nx, ny, w + 1});
            }
        }
    }
    for (int i = 0; i < b; i++) {
        auto& [x, y] = k[i];
        cout << dis[x][y] << (i < b - 1 ? "\n" :"");
    }
    return 0;
}
