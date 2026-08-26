#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

ll mx = 0;
vector<ll> s;
vector<ll> res;
void dfs(ll x, int i, int c) {
    if (c < 0 || x > mx) return;
    if (c == 0) {
        res.push_back(x);
        return;
    }
    if (i >= (int)s.size()) return;
    dfs(x + s[i], i + 1, c - 1);
    dfs(x, i + 1, c);
}

int main() {
    ios;
    int n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [l, r]: a) {
        cin >> l >> r;
        mx = max(mx, r);
    }
    ll c = 1;
    while (c <= mx) {
        s.push_back(c);
        c *= 2;
    }
    for (int i = 1; i < (int)s.size(); i++)
        dfs(s[i], i + 1, i - 1);
    sort(range(res));
    res.erase(unique(range(res)), res.end());
    for (int i = 0; i < n; i++) {
        auto& [l, r] = a[i];
        auto it1 = lower_bound(range(res), l);
        auto it2 = upper_bound(range(res), r);
        int cnt = it2 - it1;
        if (cnt <= 0) cout << -1;
        else cout << *it1;
        if (i < n - 1) cout << "\n";
    }
    return 0;
}