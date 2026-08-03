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
    int n, s, t; cin >> n >> s >> t;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            mp[i].push_back({v, (j != 1)});
        }
    }
    vector<ll> dis(n + 1, INF);
    deque<int> q;
    dis[s] = 0;
    q.push_front(s);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        if (u == t) break;
        for (auto& [v, w]: mp[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    cout << (dis[t] == INF ? -1 : dis[t]);
    return 0;
}
