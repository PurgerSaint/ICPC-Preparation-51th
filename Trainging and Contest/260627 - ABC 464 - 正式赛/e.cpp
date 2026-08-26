#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int h, w, q; cin >> h >> w >> q;
    vector<string> mat(h, string(w, 'A'));
    vector<pair<pair<int, int>, char>> t;
    for (int i = 0; i < q; i++) {
        int r, c;
        char x;
        cin >> r >> c >> x;
        t.push_back({{r - 1, c - 1}, x});
    }
    vector<int> fill_r(h, 0), fill_c(w, 0);
    for (int k = q - 1; k >= 0; k--) {
        int& r = t[k].first.first, c = t[k].first.second;
        char x = t[k].second;
        for (int i = r; i >= 0; i--) {
            if (fill_r[i] > c) break;
            for (int j = fill_r[i]; j <= c; j++)
                mat[i][j] = x;
            fill_r[i] = c + 1;
        }
    }
    for (int i = 0; i < h; i++)
        cout << mat[i] << (i < h - 1 ? "\n" : "");
    return 0;
}