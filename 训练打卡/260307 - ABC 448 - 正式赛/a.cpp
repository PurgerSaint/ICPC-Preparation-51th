#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val < x) {
            cout << 1;
            x = val;
        } else cout << 0;
        if (i != n - 1) cout << "\n";
    }
    return 0;
}