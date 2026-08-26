#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

vector<ll> ans;
ll mx = 0;
void dfs(ll i, vector<ll>& b, ll x, ll sum) {
    if (x == 0) {
        if (sum <= mx) ans.push_back(sum);
        return;
    }
    ll sz = b.size();
    if (i >= sz || sum >= mx || x < 0) return;
    dfs(i + 1, b, x - 1, sum + b[i]);
    dfs(i + 1, b, x, sum);
}

int main() {
    ios;
    int n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [l, r]: a) {
        cin >> l >> r;
        mx = max(mx, r);
    }
    vector<ll> b;
    ll c = 2;
    while (c <= mx) {
        b.push_back(c);
        c *= 2;
    }
    for (ll i = 1; i <= (ll)b.size(); i++) {
        dfs(i, b, i - 1, b[i - 1]);
    }
    sort(range(ans));
    ans.erase(unique(range(ans)), ans.end());
    for (int i = 0; i < n; i++) {
        auto& [l, r] = a[i];
        auto it1 = lower_bound(range(ans), l);
        auto it2 = upper_bound(range(ans), r);
        if (it1 != ans.end() && it2 > it1) {
            cout << *it1;
        } else cout << -1;
        if (i < n - 1) cout << "\n";
    }
    return 0;
}