#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 1) {
            cost += a[i + 1] - (a[i] + 1);
            a[i + 1] = a[i] + 1;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] - a[i] > 1) {
            cost += a[i - 1] - (a[i] + 1);
            a[i - 1] = a[i] + 1;
        }
    }
    return cost;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}