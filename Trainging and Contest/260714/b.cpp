#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    if (n == 1) return true;
    ll mv = 0;
    if (a[0] > 1) {
        mv = a[0] - 1;
        a[0] = 1;
    }
    // cout << "in:" << a[0] << " mv:" << mv << "\n";
    for (int i = 1; i < n; i++) {
        if (a[i - 1] >= (a[i] + mv)) {
            // cout << "a:" << a[i - 1] << " b:" << (a[i] + mv) << " c:" << a[i] << " mv:" << mv << "\n";
            return false;
        }
        if (a[i] == a[i - 1] + 1) continue;
        if (a[i] > (a[i - 1] + 1))
            mv += a[i] - (a[i - 1] + 1);
        else
            mv -= (a[i - 1] + 1) - a[i];

        // cout << "loc:" << i << " before:" << a[i];
        a[i] = a[i - 1] + 1;
        // cout << " now:" << a[i] << " mv:";
        // cout << (a[i] - a[i - 1]) << " nmw:" << mv << "\n";
    }
    /*cout << "less:" << mv << "\n";
    cout << "end: ====";
    for (int i = 1; i < n; i++)
        cout << a[i] << (i < n - 1 ? " " : "\n");*/
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