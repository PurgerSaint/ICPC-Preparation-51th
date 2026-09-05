#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    ll x, d; cin >> x >> d;
    if (2 * x > d) cout << "take it";
    else cout << "double it";
    return 0;
}
