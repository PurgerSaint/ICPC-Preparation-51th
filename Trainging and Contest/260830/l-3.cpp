#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

unordered_map<int, int> memo[25][25];
int w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (memo[a][b].count(c)) return memo[a][b][c];
    if (a < b && b < c) return memo[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return memo[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    ios;
    bool f = 0;
    while (true) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        if (f) cout << "\n";
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c);
        f = 1;
    }
    return 0;
}