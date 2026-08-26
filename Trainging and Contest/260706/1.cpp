#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n, m, a, b; cin >> n >> m >> a >> b;
    int cp = 0;
    if (m >= n) cp = b;
    else cp = min((n / m) * b + (n % m ? 1 : 0) * b, (n / m) * b + (n % m) * a);
    int full = n * a;
    cout << min(full, cp);
    return 0;
}