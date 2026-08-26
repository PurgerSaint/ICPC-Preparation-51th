#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int m, a, b; cin >> m >> a >> b;

    vector<vector<bool>> bad(m, vector<bool>(m, false));
    queue<pair<int, int>> q;
    auto in = [&](int x, int y) {
        if (bad[x][y]) return;
        bad[x][y] = true;
        q.push({x, y});
    };
    for (int i = 0; i < m; i++) {
        in(i, 0);
        in(0, i);
    }

    vector<vector<int>> inv(m);
    for (int x = 0; x < m; x++)
        inv[(b * x) % m].push_back(x);

    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int y = t.first, z = t.second;

        int target = (z - (a * y % m) + m) % m;

        for (int& x: inv[target]) {
            if (!bad[x][y]) in(x, y);
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (!bad[i][j])
                cnt++;
    cout << cnt;
    return 0;
}