#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

void solve(int tt) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int t; cin >> t;
            if (i == n) a[j] = t;
        }
    }
    int num = 0, k = 1;
    for (int i = n - 1; i >= 0; i--) {
        num += k * a[i];
        cout << num % 3 << " ==\n";
        k *= 10;
    }
    int q; cin >> q;
    while (q--) {
        int p; cin >> p;
        cout << (num % p) << (q ? "\n" : "");
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve(t);
        if (t) cout << "\n";
    }
    return 0;
}