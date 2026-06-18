#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int x; cin >> x;
    cout << a[x - 1];
    return 0;
}