#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (string& t: s) cin >> t;
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1}, dy = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '?') continue;
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (s[nx][ny] == '*') cnt++;
            }
            s[i][j] = '0' + cnt;
        }
    for (int i = 0; i < n; i++)
        cout << s[i] << (i < n - 1 ? "\n" : "");
    return 0;
}