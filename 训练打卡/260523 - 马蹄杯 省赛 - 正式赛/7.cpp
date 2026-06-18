#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

ll solve() {
    int n, m; ll k; cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    for (vector<int>& p: mat)
        for (int& t: p)
            cin >> t;
    vector<vector<ll>> sum(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    auto getsum = [&](int r1, int c1, int r2, int c2) -> ll {
        return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
    };
    int cnt = INT_MAX;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++) {
            for (int i = x; i < n; i++)
                for (int j = y; j < m; j++) {
                    if (getsum(min(x, i), min(j, y), max(x, i), max(j, y)) == k) {
                        cnt = min(cnt, (i - x + 1) * (j - y + 1));
                    }
                }
        }
    return cnt != INT_MAX ? cnt : -1;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}

// 给与n列m行的矩阵，问是否存在一个最小矩阵（矩阵内元素个数最少），使得矩阵和为k，有就输出该矩阵元素个数，否则-1