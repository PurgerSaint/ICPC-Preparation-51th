#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, s, a, b; cin >> n >> s >> a >> b;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        c.emplace_back(x, y);
    }
    sort(range(c), [](pair<int, int>& x, pair<int, int>& y){
        return x.second < y.second;
    });
    int l = a - b, r = a + b;
    int cnt = 0;
    for (int i = 0; i < n && s; i++) {
        auto& [h, w] = c[i]; 
        if (h < l || r < h || s < w) continue;
        s -= w;
        cnt++;
    }
    cout << cnt;
    return 0;
}