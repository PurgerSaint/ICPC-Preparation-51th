#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int node; ll w;
    bool operator<(const state& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    int n; ll d; cin >> n >> d;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    dis[1] = 0;
    priority_queue<state> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (int& v: mp[u]) {
            if (w + 1 < dis[v]) {
                dis[v] = w + 1;
                pq.push({v, w + 1});
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (dis[i] > d) continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}