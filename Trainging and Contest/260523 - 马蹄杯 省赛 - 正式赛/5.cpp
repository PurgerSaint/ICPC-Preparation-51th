#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
ll g(ll n) {
    string s = to_string(n);
    int sz = s.length();
    ll sum = 0;
    for (int i = sz - 1; i >= 0; i--)
        sum += s[i] - '0';
    return sum;
}
ll f(ll n) {
    if (n <= 5) return n * n + 2 * n + 1;
    ll t = f(n / 2);
    return g(t * t) + g(n / 5);
}

int main() {
    ll n; cin >> n;
    cout << f(n);
    return 0;
}