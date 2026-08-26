#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    /*
    ll n; cin >> n;
    ll cnt = 0;
    for (ll i = 3; i <= (cnt % 300); i += 3)
    */
    int cnt = 0;
    for (int i = 3; i <= 300; i += 3)
        cnt++;
    cout << cnt;
    return 0;
}