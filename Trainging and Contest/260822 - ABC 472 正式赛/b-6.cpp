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
    for (int i = 1; i < x; i++) {
        int a = x - y;
        int b = y * (x - 1) - i * (y - 1);
        int g = gcd(a, b);
        cout << (a / g) << " " << (b / g) << "\n";
    }
    cout << "1 1";
    return 0;
}