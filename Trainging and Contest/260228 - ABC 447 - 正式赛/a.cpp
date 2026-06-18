#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m; cin >> n >> m;
    cout << ((m * 2 - 1) <= n ? "Yes" : "No");
    return 0;
}