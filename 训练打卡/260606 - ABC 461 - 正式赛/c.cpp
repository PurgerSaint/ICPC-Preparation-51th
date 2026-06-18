#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;
struct state {
    int c; ll v;
    state(int a, ll b): c(a), v(b) {}
    bool operator<(const state& other) const {
        return v < other.v;
    }
};
int main() {
    ios;
    int n, k, m; cin >> n >> k >> m;
    priority_queue<state> a, b;
    for (int i = 0; i < n; i++) {
        int c; ll v; cin >> c >> v;
        a.push({c, v});
    }
    int cnt = 0, c_cnt = 0;
    ll sum = 0;
    set<int> color;
    while (c_cnt < m) {
        state t = a.top(); a.pop();
        if (!color.count(t.c)) {
            cnt++;
            c_cnt++;
            sum += t.v;
            color.insert(t.c);
            // cout << "cnt:" << cnt << " " << t.c << " " << t.v << "\n";
        } else b.push(t);
    }
    while (!b.empty()) {
        state t = b.top(); b.pop();
        a.push(t);
    }
    while (cnt < k && !a.empty()) {
        state t = a.top(); a.pop();
        sum += t.v;
        cnt++;
        // cout << "cnt:" << cnt << " " << t.c << " " << t.v << "\n";
    }
    cout << sum;
    return 0;
}