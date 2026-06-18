#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
int main() {
    ios;
    int x, y; cin >> x >> y;
    if (x % 16 == 0 && (x / 16) * 9 == y) cout << "Yes";
    else cout << "No";
    return 0;
}