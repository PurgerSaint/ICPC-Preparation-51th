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

vector<ll> Dijkstar(vector<vector<pair<int, ll>>>& mp, int& n, int s) {
    vector<ll> dis(n + 1, INF);
    priority_queue<state> pq;
    dis[s] = 0;
    pq.push({s, dis[s]});
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (w != dis[u]) continue;
        for (auto& [v, w1]: mp[u]) {
            if (w + w1 < dis[v]) {
                dis[v] = w + w1;
                pq.push({v, w + w1});
            }
        }
    }
    return dis;
}

int main() {
    ios;
    int c, n, m; cin >> c >> n >> m;
    vector<int> cows(c);
    for (int& cow: cows) cin >> cow;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        vector<ll> dis = Dijkstar(mp, n, i);
        ll s = 0;
        for (int& cow: cows)
            s += dis[cow];
        ans = min(ans, s);
    }
    cout << ans;
    return 0;
}
