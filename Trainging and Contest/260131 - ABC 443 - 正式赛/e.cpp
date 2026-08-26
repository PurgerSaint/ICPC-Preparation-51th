#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

string solve() {
    int n, c; cin >> n >> c;
    string res(n, '0');
    vector<string> mp(n);
    for (string& s: mp)
        cin >> s;
    vector<int> wall(n);
    for (int j = 0; j < n; j++) {
        if (mp[n - 1][j] == '.') {
            for (int i = n - 2; i >= 0; i--)
                if (mp[i][j] == '#') {
                    wall[j] = i + 1;
                    break;
                }
        }
    }

    vector<bool> cur(n), nxt(n);
    cur[c - 1] = true;

    auto po = [&](auto&& self, int j) -> void {
        wall[j]--;
        for (int i = wall[j] - 1; i >= 0; i--) {
            if (mp[i][j] == '#') {
                wall[j] = i + 1;
                break;
            }
        }
    };

    for (int i = n - 1; i > 0; i--) {
        fill(nxt.begin(), nxt.end(), false);

        for (int j = 0; j < n; j++) {
            if (cur[j]) {
                for (int dj: {-1, 0, 1}) {
                    int nj = j + dj;
                    if (nj < 0 || nj >= n) continue;

                    if (mp[i - 1][nj] == '.') nxt[nj] = true;
                    else if (wall[nj] == i) {
                        nxt[nj] = true;
                        po(po, nj);
                    }
                }
            }
        }

        cur = nxt;
    }
    for (int i = 0; i < n; i++)
        res[i] = cur[i] ? '1' : '0';
    return res;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}