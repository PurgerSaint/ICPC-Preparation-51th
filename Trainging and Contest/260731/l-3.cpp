#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
const ll INF = 1LL << 60;


int main() {
    ios;
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<string> mp(n, string(m, ' '));
        for (string& s: mp) cin >> s;

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        pair<int, int> c1, c2;
        cin >> c1.first >> c1.second >> c2.first >> c2.second;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        deque<pair<int, int>> q;
        q.push_front(c1);
        dis[c1.first][c1.second] = 0;
        while (!q.empty()) {
            pair<int, int> c = q.front(); q.pop_front();
            if (c == c2) break;
            for (int i = 0; i < 4; i++) {
                int nx = c.first + dx[i], ny = c.second + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int cost = mp[nx][ny] != mp[c.first][c.second];
                if (dis[nx][ny] > dis[c.first][c.second] + cost) {
                    dis[nx][ny] = dis[c.first][c.second] + cost;
                    if (!cost) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
        cout << dis[c2.first][c2.second] << "\n";
    }
    return 0;
}
