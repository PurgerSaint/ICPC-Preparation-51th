#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    } 
};

int main() {
    ios;
    int n; cin >> n;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) {
            ll w; cin >> w;
            if (w == 0) continue;
            mp[u].push_back({v, w});
        }
    priority_queue<state> pq;
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);
    dis[0] = 0;
    pq.push({0, 0});
    ll sum = 0, cnt = 0;
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (vis[u]) continue;
        if (dis[u] != w) continue;
        vis[u] = 1;
        sum += w;
        cnt++;
        for (auto& [v, w1]: mp[u]) {
            if (!vis[v] && w1 < dis[v]) {
                dis[v] = w1;
                pq.push({v, w1});
            }
        }
    }
    if (cnt < n) cout << -1;
    else cout << sum;
    return 0;
}
