#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    ll ax = 0, ay = 0, az = 0;
    int n; cin >> n;
    while (n--) {
        int x, y, z; cin >> x >> y >> z;
        ax += x;
        ay += y;
        az += z;
    }
    if (ax == 0 && ay == 0 && az == 0) cout << "YES";
    else cout << "NO";
    return 0;
}