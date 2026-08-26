#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solvE() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int W; cin >> W;
    vector<string> h(n);
    for (string& s: h) cin >> s;
    auto id = [&](int city, int day) {
        return city * W + day;
    };
    int V = n * W;
    vector<int> in(V, 0);

    for (int city = 0; city < n; city++) {
        for (int day = 0; day < W; day++) {
            if (h[city][day] == 'x') continue;

            int pre_day = (day + W - 1) % W;
            if (h[city][pre_day] == 'o') in[id(city, day)]++;

            for (int& other_city: mp[city]) {
                if (h[other_city][pre_day] == 'o')
                    in[id(city, day)]++;
            }
        }
    }
    queue<int> q;
    for (int state = 0; state < V; state++) {
        if (in[state] == 0)
            q.push(state);
    }
    int remove = 0;
    while (!q.empty()) {
        int state = q.front(); q.pop();
        remove++;
        int city = state / W, day = state % W;
        if (h[city][day] == 'x') continue;
        int next_day = (day + 1) % W;

        auto remove_city = [&](int next_city) {
            if (h[next_city][next_day] == 'o') {
                int to = id(next_city, next_day);
                in[to]--;
                if (!in[to]) q.push(to);
            }
        };
        remove_city(city);
        for (int& next_city: mp[city]) {
            remove_city(next_city);
        }
    }
    return remove < V ? "Yes" : "No";
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solvE();
        if (t) cout << "\n";
    }
    return 0;
}
