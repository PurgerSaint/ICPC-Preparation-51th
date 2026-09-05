#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    pair<int, int> k;
    cin >> k.first >> k.second;
    vector<pair<int, int>> a(n);
    for (auto& [l, r]: a) cin >> l >> r;
    sort(range(a), [](pair<int, int>& x, pair<int, int>& y){
        return (ll)x.first * x.second < (ll)y.first * y.second;
    });
    ll x = k.first, mx = 0;
    for (auto& [l, r]: a) {
        mx = max(mx, x / r);
        x *= l;
    }
    cout << mx;
    return 0;
}