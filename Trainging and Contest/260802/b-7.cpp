#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int x, y, cnt;
    ll dis;
    state(int x1, int y1, int c, ll d): x(x1), y(y1), cnt(c), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (string& t: a) cin >> t;
    pair<int, int> start, end;
    vector<vector<pair<int, int>>> t(26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = a[i][j];
            if (c == '=')
                end = {i, j};
            else if (c == '@')
                start = {i, j};
            else if ('A' <= c && c <= 'Z')
                t[c - 'A'].push_back({i, j});
        }
    }
    map<pair<int, int>, pair<int, int>> tran;
    for (int i = 0; i < 26; i++) {
        if ((int)t[i].size() != 2) continue;
        pair<int, int>& a = t[i][0], b = t[i][1];
        tran[a] = b;
        tran[b] = a;
    }
    vector<vector<ll>> dis(n, vector<ll>(m, INF));
    priority_queue<state> pq;
    dis[start.first][start.second] = 0;
    pq.push({start.first, start.second, 1, 0});
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto [x, y, cnt, w] = pq.top(); pq.pop();
        if (w != dis[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == '#') continue;
            if (tran.count({nx, ny})) {
                if (cnt == 0) continue;
                pair<int, int>& loc = tran[{nx, ny}];
                nx = loc.first;
                ny = loc.second;
            }
            if (w + 1 < dis[nx][ny]) {
                dis[nx][ny] = w + 1;
                pq.push({nx, ny, 1, w + 1});
            }
        }
    }
    cout << dis[end.first][end.second];
    return 0;
}
