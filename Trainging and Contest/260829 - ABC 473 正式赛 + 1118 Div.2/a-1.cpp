#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (i > (n / 2)) sum += t;
    }
    cout << sum;
    return 0;
}