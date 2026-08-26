#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;
    if (a == b) return 0;
    if (!accumulate(range(a), 0) || accumulate(range(b), 0) == n) return -1;
    
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            sum += a[i];
    return sum % 2 ? 1 : 2;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0;
}