#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

struct road {
    int city;
    int day;
    int start;
    road(int c, int d, int s): city(c), day(d), start(s) {}
};

class UnionFold {
    private:
        int count;
        vector<int> parent;
        vector<int> size;
    public:
        UnionFold(int n): count(n), parent(n + 1), size(n + 1) {
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        void unionset(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return;
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
        }

        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
};

string solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    int w; cin >> w;
    vector<vector<int>> holiday(w);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++)
            if (s[j] == 'o')
                holiday[j].push_back(i + 1);
    }
    for (vector<int>& days: holiday)
        if (days.empty())
            return "No";
    
    queue<road> lt;
    for (int& city: holiday[0])
        lt.push({city, 0, city});

    set<pair<int, int>> hash;
    set<int> end;
    UnionFold u(n + 1);

    while (!lt.empty()) {
        road p = lt.front();
        lt.pop();
        int& city = p.city, day = p.day, start = p.start;

        
        if (day + 1 == w) {
            if (mp[city].count(start)) return "Yes";
            u.unionset(start, city);
            end.insert(city);
            continue;
        }
        day++;

        for (int& next_city: holiday[day]) {
            if (hash.count({next_city, day})) continue;
            if (next_city == city || mp[city].count(next_city)) {
                hash.insert({next_city, day});
                lt.push({next_city, day, start});
            }
        }
    }

    for (const int& city: end)
        if (city == u.find(city))
            return "Yes";

    return "No";
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}