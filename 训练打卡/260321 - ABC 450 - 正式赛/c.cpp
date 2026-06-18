#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
vector<string> mp;
int h, w;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w) return;
    if (mp[i][j] != '.') return;
    mp[i][j] = '*';

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    ios;
    cin >> h >> w;
    mp = vector<string>(h);
    for (int i = 0; i < h; i++)
            cin >> mp[i];
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        if (mp[i][0] == '.') dfs(i, 0);
        if (mp[i][w - 1] == '.') dfs(i, w - 1); 
    }
    for (int j = 0; j < w; j++) {
        if (mp[0][j] == '.') dfs(0, j);
        if (mp[h - 1][j] == '.') dfs(h - 1, j); 
    }
    for (int i = 1; i < h - 1; i++)
        for (int j = 1; j < w - 1; j++) {
            if (mp[i][j] == '.') {
                cnt++;
                dfs(i, j);
            }
        }
    cout << cnt;
    return 0;
}