#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int x, y, t;
    bool operator<(const state& other) const {
        return t > other.t;
    }
};

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<state> a(m);
    for (auto& [x, y, t]: a)
        cin >> t >> x >> y;
    vector<int> dp(m, 1);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = i + 1; j < m; j++) {
            int dis = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            int time = a[j].t - a[i].t;
            if (dis <= time)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(range(dp));
    return 0;
}
