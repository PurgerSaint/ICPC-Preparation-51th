#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    ll p, q; cin >> p >> q;
    return p < q && 3 * p >= 2 * q;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "Bob" : "Alice");
        if (tt) cout << "\n";
    }
    return 0;
}