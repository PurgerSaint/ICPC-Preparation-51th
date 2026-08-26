#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        t % 2 ? a.push_back(i) : b.push_back(i);
    }
    if ((int)a.size() == 1) cout << a[0];
    else cout << b[0];
    return 0;
}