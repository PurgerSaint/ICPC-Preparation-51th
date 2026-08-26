#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    vector<int> b(m);
    for (int& t: b) cin >> t;
    sort(range(a));
    ll ans = 0;
    for (int& t: b) {
        auto it = lower_bound(range(a), t);
        if (it == a.end()) ans += t - a.back();
        else if (*it == t) continue;
        else if (it == a.begin()) ans += a[0] - t;
        else ans += min(*it - t, t - *(it - 1));
    }
    cout << ans;
    return 0;
}