#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int h, w, k; cin >> h >> w >> k;
    vector<string> a(h);
    for (string& s: a) cin >> s;
    vector<vector<int>> dis(h, vector<int>(w, h * w));
    int boom = 0;
    vector<int> cnt_r(h, 0), cnt_c(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                boom++;
                cnt_r[i]++;
                cnt_c[j]++;
            }
        }
    }
    if (boom == 0) {
        cout << h * w;
        return 0;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!cnt_r[i] && !cnt_c[j]) {
                // cout << "safe:" << i << " " << j << "\n";
                vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
                queue<pair<int, int>> q;
                q.push({i, j});
                dis[i][j] = 0;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    if (dis[x][y] + 1 > k) continue;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (a[nx][ny] != '.') continue;
                        if (dis[x][y] + 1 < dis[nx][ny]) {
                            dis[nx][ny] = dis[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') continue;
            if (dis[i][j] <= k) ans++;
        }
    }
    cout << ans;
    return 0;
}