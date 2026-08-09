#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n; cin >> n;
    multiset<ll> b;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        b.insert(t);
    }
    ll sum = 0;
    vector<ll> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        auto it = b.lower_bound(1 - sum);
        if (it == b.end()) return 0;
        sum += *it;
        b.erase(it);
        ans[i] = sum;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << (i < n ? " " : "");
    return 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        if (!solve()) cout << -1;
        if (t) cout << "\n";
    }
    return 0;
}
