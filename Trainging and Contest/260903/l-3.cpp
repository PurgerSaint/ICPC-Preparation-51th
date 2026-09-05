#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

vector<vector<pair<int, ll>>> mp;
int n, k;

pair<int, ll> dfs(int u, int fa, ll d) {
    ll mx_dis = 0;
    int gas_cnt = 0;

    for (auto& [v, w]: mp[u]) {
        if (v == fa) continue;
        auto [c_cnt, c_dis] = dfs(v, u, d);
        gas_cnt += c_cnt;
        ll dis = c_dis + w;
        if (dis > d) {
            gas_cnt++;
            mx_dis = max(mx_dis, w);
        } else {
            mx_dis = max(mx_dis, dis);
        }
    }
    return {gas_cnt, mx_dis};
}

bool check(ll d) {
    auto [gas_cnt, mx_dis] = dfs(1, -1, d);

    if (mx_dis > d) gas_cnt++;
    return gas_cnt <= k;
}

int main() {
    ios;
    cin >> n >> k;
    mp = vector<vector<pair<int, ll>>>(n + 1);
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
        mp[v].emplace_back(u, w);
        sum += w;
    }
    ll l = 0, r = sum, ans = 0;
    while (l < r) {
        ll mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else l = mid + 1;
    }
    cout << ans;
    return 0;
}