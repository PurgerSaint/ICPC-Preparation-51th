#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    ll t; cin >> t;
    vector<ll> b;
    ll c = 1;
    while (c <= t) {
        b.push_back(c);
        c *= 10;
    }
    string x, y;
    if ((int)b.size() == 1 || t == 10) {
        x = to_string(1);
        y = to_string(t - 1);
    } else {
        ll& now = b.back();
        ll& last = *(b.end() - 2);
        if (now <= t && t < now + last) {
            x = to_string(last);
            y = to_string(t - last);
        } else {
            x = to_string(now);
            y = to_string(t - now);
        }
    }
    if (x.length() == y.length() && x > y) {
        cout << x << y;
    } else cout << y << x;
    return 0;
}