#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    ll x; cin >> x;
    int q; cin >> q;
    
    priority_queue<ll> l;
    priority_queue<ll, vector<ll>, greater<ll>> r;

    auto add = [&](ll t) -> void {
        if (l.empty() || t < l.top()) l.push(t);
        else r.push(t);

        while (l.size() < r.size() + 1) {
            l.push(r.top());
            r.pop();
        }
        while (l.size() > r.size() + 1) {
            r.push(l.top());
            l.pop();
        }
    };

    add(x);

    while (q--) {
        ll a, b; cin >> a >> b;
        add(a); add(b);
        cout << l.top() << (q != 0 ? "\n" : "");
    }
    return 0;
}