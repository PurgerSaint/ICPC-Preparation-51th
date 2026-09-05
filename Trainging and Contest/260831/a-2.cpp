#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        p.emplace_back(l, r);
    }
    sort(range(p), [](pair<int, int>& x, pair<int, int>& y){
        return x.second < y.second;
    });
    int cnt = 1, last = p[0].second;
    for (auto it = p.begin() + 1; it != p.end(); it++) {
        auto& [l, r] = *it;
        if (l >= last) {
            cnt++;
            last = r;
        }
    }
    cout << cnt;
    return 0;
}