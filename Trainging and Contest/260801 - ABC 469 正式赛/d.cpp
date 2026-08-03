#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> game(m);
    for (auto& [a, b]: game)
        cin >> a >> b;
    auto get_cand = [&](int fixed) -> vector<int> {
        vector<int> cand;
        bool f = 0;
        for (auto& [a, b]: game) {
            if (a == fixed || b == fixed) continue;
            if (!f) {
                cand = {a, b};
                f = 1;
            } else {
                vector<int> next;
                for (int& x: cand) {
                    if (x == a || x == b)
                        next.push_back(x);
                }
                cand = next;
            }
        }
        if (!f) {
            cand.clear();
            for (int x = 1; x <= n; x++) {
                if (x != fixed)
                    cand.push_back(x);
            }
        }
        return cand;
    };
    int& A1 = game[0].first, B1 = game[0].second;
    vector<int> candA = get_cand(A1), candB = get_cand(B1);
    ll ans = candA.size() + candB.size();
    bool f = 1;
    for (auto& [a, b]: game) {
        if (a != A1 && b != A1 && a != B1 && b != B1) {
            f = 0;
            break;
        }
    }
    if (f) ans--;
    cout << ans;
    return 0;
}