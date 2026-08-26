#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

void solve() {
    int n, m; ll h; cin >> n >> m >> h;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, vector<pair<int, ll>>> op;
    for (int i = 0; i < m; i++) {
        int b; ll c; cin >> b >> c;
        op[b - 1].push_back({i, c});
    }
    int mx = 0;
    for (pair<const int, vector<pair<int, ll>>>& p: op) {
        ll t = a[p.first];
        for (auto& [time, val]: p.second) {
            t += val;
            if (t > h) {
                t = a[p.first];
                mx = max(mx, time);
                // cout << "max:" << time << "\n";
            }
        }
    }
    // cout << "end_time:" << mx << "\n";
    for (pair<const int, vector<pair<int, ll>>>& p: op) {
        ll& t = a[p.first];
        for (auto it = p.second.rbegin(); it != p.second.rend(); it++) {
            auto& [time, val] = *it;
            if (time <= mx) break;
            t += val;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << (i < n - 1 ? " " : "");
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        solve();
        if (tt) cout << "\n";
    }
    return 0;
}