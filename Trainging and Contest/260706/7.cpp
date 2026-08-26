#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        auto it = lower_bound(a.begin(), a.end(), t);
        cout << (it - a.begin() + 1) << (m ? "\n" : "");
    }
    return 0;
}