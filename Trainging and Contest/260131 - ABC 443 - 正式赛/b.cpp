#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    ll n, k; cin >> n >> k;
    ll i = 0, sum = n, t = n;
    while (sum < k) {
        i++; t++;
        sum += t;
    }
    cout << i;
    return 0;
}