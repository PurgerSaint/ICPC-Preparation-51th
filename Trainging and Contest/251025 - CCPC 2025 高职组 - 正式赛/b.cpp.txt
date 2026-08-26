#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
vector<vector<pair<int,ll>>> mp;
vector<ll> height;
int n, m, h1;
struct State {
    int node;
    ll weight;
    ll h;
    State(int n, ll w, ll h1) : node(n), weight(w), h(h1) {}
    bool operator<(const State& other) const {
        return weight > other.weight;
    }
};
void Dijkstra(int start) {
    vector<bool> vis(n + 1, false);
    vector<ll> dis(n + 1, LLONG_MAX);
    priority_queue<State> pq;
    pq.push(State(start, 0, 0));
    dis[start] = 0;
    while (!pq.empty()) {
        State t = pq.top(); pq.pop();
        int u = t.node; ll w = t.weight, h = t.h;
        if (vis[u]) continue;
        vis[u] = true;
        for (pair<int, ll>& p : mp[u]) {
            int v = p.first;
            ll w2 = p.second + w;
            ll h2 = height[v] <= height[u] ? 0 : (h + (height[v] - height[u]));

            
             if (height[v] - height[u] > h1) continue;

            if (h2 > h1) {
                ll w3 = LLONG_MAX;
                ll h3 = -1;
                for (pair<int, ll>& k : mp[u]) {
                    if (k.first == v) continue;
                    if (height[k.first] > height[u]) continue;
                    ll h4 = height[u] - height[k.first];
                    if (h4 <= h1 && (w2 + 2 * k.second < w3)) {
                        h3 = h4;
                        w3 = w2 + 2*k.second;
                    }
                }
                if (h3 != -1) {
                    h2 = h3;
                    w2 = w3;
                }
            }

            if (h2 > h1) continue;
            if (dis[v] > w2){
                dis[v] = w2;
                pq.push(State(v, dis[v], h2));
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) cout << -1;
        else cout << dis[i];
        if (i != n) cout << " ";
    }
}
int main() {
    IOS;
    cin >> n >> m >> h1;
    height = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }
    mp = vector<vector<pair<int,ll>>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll t;
        cin >> u >> v >> t;
        mp[u].push_back({v, t});
        mp[v].push_back({u, t});
    }
    Dijkstra(1);
    return 0;
}