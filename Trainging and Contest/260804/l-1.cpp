#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int u; ll w;
    bool operator<(const state& a) const {
        return w > a.w;
    }
};

ll prim(vector<vector<pair<int, int>>>& mp, int start, int n) {
    ll sum = 0, cnt = 0;
    priority_queue<state> pq;
    vector<bool> vis(n + 1, 0);
    vector<ll> dis(n + 1, INF);
    pq.push({start, 0});
    dis[start] = 0;
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
    return cnt == n ? sum : -1;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    int sum = prim(mp, 1, n);
    if (sum == -1) cout << "orz";
    else cout << sum;
    return 0;
}
