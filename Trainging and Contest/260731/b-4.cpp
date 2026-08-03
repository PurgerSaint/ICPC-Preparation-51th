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
    vector<vector<tuple<int, ll, int>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mp[u].push_back({v, w, i + 1});
        mp[v].push_back({u, w, i + 1});
    }
    int s; cin >> s;
    vector<ll> dis(n + 1, INF);
    vector<int> parentEdge(n + 1, -1);
    vector<ll> parentWeight(n + 1, INF);
    priority_queue<state> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        auto [u, w] = pq.top(); pq.pop();
        if (dis[u] != w) continue;
        for (auto& [v, w1, id]: mp[u]) {
            if (w + w1 < dis[v]) {
                dis[v] = w + w1;
                parentEdge[v] = id;
                parentWeight[v] = w1;
                pq.push({v, w + w1});
            } else if (dis[u] + w1 == dis[v] && w1 < parentWeight[v]) {
                parentEdge[v] = id;
                parentWeight[v] = w1;
            }
        }
    }
    ll sum = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        sum += parentWeight[i];
        ans.push_back(parentEdge[i]);
    }
    sort(range(ans));
    cout << sum << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << (it + 1 != ans.end() ? " " : "");
    return 0;
}
