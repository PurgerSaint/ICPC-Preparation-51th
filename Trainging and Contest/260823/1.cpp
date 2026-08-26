#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    ll n, k; cin >> n >> k;
    ll sum = k;
    if (k % 2) sum += 2;
    else if (k % 3 == 0) sum += 5;
    else sum += 3;
    bool f = k % 2;
    for (ll i = 3; i <= n; i++) {
        if (i % 2) sum += (f ? 3 : 2);
        else sum += (f ? 2 : 3);
    }
    cout << sum;
    return 0;
}