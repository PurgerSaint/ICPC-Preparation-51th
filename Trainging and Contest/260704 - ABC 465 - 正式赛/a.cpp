#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int a, b; cin >> a >> b;
    /*
    double c = b / 3.0 * 2;
    if (a - c > 1e-9) cout << "Yes";
    else cout << "No";
    */
    if (a > (b / 3.0 * 2)) cout << "Yes";
    else cout << "No";
    return 0;
}