#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<int> a(n), sum(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) sum[i] = sum[i - 1] + a[i];
        else sum[i] = a[i];
    }
    while (q--) {
        int k; cin >> k;
        if (k == 1) {
            int x; cin >> x;
            sum[x - 1] = sum[x - 1] - a[x - 1] + a[x];
            int t = a[x];
            swap(a[x], a[x - 1]); 
        } else if (k == 2) {
            int l, r; cin >> l >> r;
            if (l == 1) cout << sum[r - 1];
            else cout << (sum[r - 1] - sum[l - 2]);
            cout << (q != 0 ? "\n" : "");
        }
    }
    return 0;
}