#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int p, q; cin >> p >> q;
    int x, y; cin >> x >> y;
    cout << (((x >= p && x < (p + 100)) && (y >= q && y < (q + 100))) ? "Yes" : "No");
    return 0;
}