#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(a.begin(), a.end());
    int q; cin >> q;
    while (q--) {
        ll t; cin >> t;
        auto it = upper_bound(a.begin(), a.end(), t);
        cout << (it - a.begin());
        if (q) cout << "\n";
    }
    return 0;
}