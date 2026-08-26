#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int a, b, c; cin >> a >> b >> c;
    int x1 = a + b + c, x2 = a * b * c,
        x3 = a * (b + c), x4 = (a + b) * c,
        x5 = a * b + c, x6 = a + b * c;
    cout << max(x1, max(x2, max(x3, max(x4, max(x5, x6)))));
    return 0;
}