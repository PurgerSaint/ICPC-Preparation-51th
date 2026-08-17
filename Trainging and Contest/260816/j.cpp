#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios;
    int x, y; cin >> x >> y;
    if (x != y) {
        int t = gcd(x - y, x);
        cout << ((x - y) / t) << " " << (x / t) << "\n";
    } else {
        cout << 1 << " " << x << (x > 1 ? "\n" : "");
    }
    for (int i = x - 1; i >= 1; i--)
        cout << 1 << " " << i << (i > 1 ? "\n" : "");
    return 0;
}