#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;
int main() {
    ios;
    int h, w, k; cin >> h >> w >> k;
    vector<vector<int>> mat(h, vector<int>(w, 0));
    // int t_sum = 0;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            mat[i][j] = s[j] - '0';
            // t_sum += mat[i][j];
            // cout << mat[i][j] << (j < w - 1 ? " " : "\n");
        }
    }
    vector<vector<int>> sum(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            // cout << sum[i][j] << (j < w ? " " : "");
        }
        // cout << "\n";
    }
    if (sum[h][w] < k) {
        cout << 0;
        return 0;
    }
    auto getsum = [&](int r1, int c1, int r2, int c2) {
        return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
    };

    ll cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            for (int x = i; x < h; x++)
                for (int y = j; y < w; y++)
                    if (getsum(i, j, x, y) == k)
                        cnt++;
        }
    cout << cnt;
    return 0;
}