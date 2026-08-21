#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> b;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t > 0) {
            if (b.empty() || b.back().back().first + 1 < i) {
                b.push_back({});
            }
            b.back().push_back({i, t});
        }
    }
    if (b.size() >= 2 && b[0][0].first == 1 && b.back().back().first == n) {
        for (auto& p: b[0]) b.back().push_back(p);
        b[0].clear();
    }
    vector<pair<int, int>> res;
    if ((int)b.size() > 1) {
        for (vector<pair<int, int>>& p: b) {
            if (p.empty()) continue;
            for (auto it = p.begin(); it != p.end(); it++) {
                auto& [loc, cnt] = *it;
                if (!cnt) continue;
                int end = loc;
                while (cnt) {
                    cnt--;
                    auto it1 = it + 1;
                    while (it1 != p.end()) {
                        auto& [loc2, cnt2] = *it1;
                        // cout << "==" << loc2 << " " << cnt2 << "\n";
                        if (!cnt2) break;
                        cnt2--;
                        end = loc2;
                        it1++;
                    }
                    res.push_back({loc, end});
                }
            }
        }
    } else {
        int ans = -1;
        vector<pair<int, int>> r;
        for (int i = 0; i < n; i++) {
            auto& [loc, cnt] = b[0][i];
            b[0].push_back({loc + n, cnt});
        }
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> c = b[0];
            int j = i;
            while (j < 2 * n) {
                auto& [loc, cnt] = c[j];
                if (!cnt) {
                    j++;
                    continue;
                }
                int end = j, k = j + 1;
                while (k < 2 * n) {
                    auto& [loc2, cnt2] = c[k];
                    if (!cnt2) break;
                    cnt2--;
                    c[(k + n) % (2 * n)].second--;
                    end = loc2;
                    k++;
                }
                r.push_back({loc, end});
                j = (j + 1) % n;
                if (j == i) break;
            }
            cout << j << " " << (int)r.size() << "\n";
            if (ans == -1 || ans > (int)r.size()) {
                res = r;

            }
            r.clear();
        }
    }
    int sz = res.size();
    cout << sz;
    if (sz <= 2 * 1e5) {
        cout << "\n";
        for (auto it = res.begin(); it != res.end(); it++){
            auto& [l, r] = *it;
            cout << l << " " << r;
            if (it + 1 != res.end()) cout << "\n";
        }
    }
    return 0;
}