#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (auto& [x, y]: p)
        cin >> x >> y;
    
    auto get_card = [&](int fixed) -> vector<int> {
        vector<int> n1;
        bool f = 0;
        for (int i = 1; i < m; i++) {
            auto& [x, y] = p[i];
            if (x == fixed || y == fixed) continue;
            if (!f) {
                n1 = {x, y};
                f = 1;
            } else {
                vector<int> nd;
                for (int& t: n1)
                    if (t == x || t == y)
                        nd.push_back(t);
                n1 = nd;
            }
        }
        if (!f) {
            n1.clear();
            for (int i = 1; i <= n; i++)
                if (i != fixed)
                    n1.push_back(i);
        }
        return n1;
    };
    int& p1 = p[0].first, p2 = p[0].second;
    vector<int> a1 = get_card(p1), b1 = get_card(p2);
    ll ans = a1.size() + b1.size();
    bool f = 1;
    for (auto& [x, y]: p)
        if (x != p1 && y != p1 && x != p2 && y != p2) {
            f = 0;
            break;
        }
    if (f) ans--;
    cout << ans;
    return 0;
}
