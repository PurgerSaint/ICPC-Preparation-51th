#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const ll INF = 1LL << 60;
struct state {
    int node;
    ll dis;
    state(int n, ll d): node(n), dis(d) {}
    bool operator<(const state& other) const {
        return dis > other.dis;
    }
};

int main() {
    ios;
    int n, a, b; cin >> n >> a >> b;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int t; cin >> t;
            mp[i].push_back({t, j != 1});
        }
    }
    vector<ll> dis(n + 1, INF);
    deque<int> q;
    dis[a] = 0;
    q.push_back(a);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto& [v, cost]: mp[u]) {
            if (dis[u] + cost < dis[v]) {
                dis[v] = cost + dis[u];
                if (cost == 0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    cout << (dis[b] == INF ? -1 : dis[b]);
    return 0;
}
