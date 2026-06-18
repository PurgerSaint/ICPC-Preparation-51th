#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> mp(n);
    vector<string> mp2(n, string(m, '.'));
    vector<vector<int>> cnt(n, vector<int>(m, -1));
    for (string& s: mp)
        cin >> s;
    
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool has_black = false;
            if (mp[i][j] == '.') {
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (mp[nx][ny] == '#') {
                        has_black = true;
                        break;
                    }
                }
                mp2[i][j] = has_black ? '#' : '.';
                if (has_black) {
                    cnt[i][j] = 0;
                    q.push({i, j});
                }
            } else mp2[i][j] = '.';
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (cnt[nx][ny] == -1) {
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cnt[i][j] != -1 && cnt[i][j] % 2) cout << "#";
            else cout << ".";
        }
        if (i < n - 1) cout << "\n";
    }
    return 0;
}