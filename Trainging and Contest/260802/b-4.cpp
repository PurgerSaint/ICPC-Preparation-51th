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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (string& s: a) cin >> s;
    int V = (n + 1) * (m + 1);
    auto id = [&](int x, int y) {
        return x * (m + 1) + y;
    };
    vector<vector<pair<int, ll>>> mp(V + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lu = id(i, j), ru = id(i, j + 1);
            int ld = id(i + 1, j), rd = id(i + 1, j + 1);

            mp[lu].push_back({rd, a[i][j] != '\\'});
            mp[rd].push_back({lu, a[i][j] != '\\'});
            mp[ru].push_back({ld, a[i][j] != '/'});
            mp[ld].push_back({ru, a[i][j] != '/'});
        }
    }
    vector<ll> dis(V + 1, INF);
    priority_queue<state> pq;
    int s = id(0, 0), t = id(n, m);
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
    if (dis[t] == INF) cout << "NO SOLUTION";
    else cout << dis[t];
    return 0;
}
