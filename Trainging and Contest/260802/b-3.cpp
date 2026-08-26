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
    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<string> a(n);
        for (string& s: a) cin >> s;
        pair<int, int> s, t;
        cin >> s.first >> s.second >> t.first >> t.second;
        vector<vector<ll>> dis(n, vector<ll>(m, INF));
        dis[s.first][s.second] = 0;
        deque<pair<int, int>> dq;
        dq.push_front(s);
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            if (x == t.first && y == t.second) break;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int cost = (a[x][y] != a[nx][ny]);
                if (dis[x][y]+ cost < dis[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + cost;
                    if (cost) dq.push_back({nx, ny});
                    else dq.push_front({nx, ny});
                }
            }
        }
        cout << dis[t.first][t.second] << "\n";
    }
    return 0;
}
