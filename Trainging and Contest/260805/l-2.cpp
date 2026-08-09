#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> mp(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int t; cin >> t;
            if (t == 0) break;
            mp[i].push_back(t);
            in[t]++;
        }
    }
    queue<int> q;
    vector<int> list;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        list.push_back(u);
        for (int& v: mp[u]) {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    for (int i = 0; i < n; i++)
        cout << list[i] << (i < n - 1 ? " " : "");
    return 0;
}