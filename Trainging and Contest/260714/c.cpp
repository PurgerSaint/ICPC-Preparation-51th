#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n), loc(n + 1, -1);
    bool f = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = i + 1;
        loc[a[i]] = i;
        if (a[i] != b[i]) f = 0;
    }
    if (n == 1 || f) return true;
    int k = gcd(x, y);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        int d = abs(loc[b[i]] - i);
        if (i - min(x, y) < 0 && i + min(x, y) >= n) return false;
        if (d % k) return false;
        // cout << "loc:" << i << " nv:" << a[i] << " to:" << b[i] << "\n";
    }
    return true;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes" : "No");
        if (tt) cout << "\n";
    }
    return 0;
}