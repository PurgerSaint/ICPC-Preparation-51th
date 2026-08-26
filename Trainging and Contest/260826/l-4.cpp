#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll c; cin >> n >> c;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(range(a));
    ll cnt = 0;
    for (ll& t: a) {
        auto it1 = lower_bound(range(a), t + c);
        auto it2 = upper_bound(range(a), t + c);
        cnt += (it2 - it1);
    }
    cout << cnt;
    return 0;
}