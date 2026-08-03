#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

struct state {
    int l, r;
    int index;
    int i, j;
    state(): l(0), r(0), index(0), i(-1), j(-1) {}
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            p[i] = i - 1;
        else
            p[i] = p[i - 1];
    }
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if (p[r] < l) cout << -1 << " " << -1;
        else cout << (p[r] + 1) << " " << (r + 1);
        if (m) cout << "\n"; 
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}