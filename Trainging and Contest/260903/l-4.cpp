#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

struct state {
    int u; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n, s, t; cin >> n >> s >> t;
    vector<vector<int>> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        if (!k) continue;
        if (i - k >= 1) mp[i].push_back(i - k);
        if (i + k <= n) mp[i].push_back(i + k);
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    dis[s] = 0;
    priority_queue<state> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (u == t) break;
        if (dis[u] != w) continue;
        for (int& v: mp[u]) {
            if (w + 1 < dis[v]) {
                dis[v] = w + 1;
                pq.push({v, w + 1});
            }
        }
    }
    cout << (dis[t] == INF ? -1 : dis[t]);
    return 0;
}
