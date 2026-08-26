#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    int n; cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t % 2 == 0) a += t;
        if (t % 3 == 0) b += t;
        if (t % 5 == 0) c += t;
    }
    cout << a << " " << b << " " << c;
    return 0;
}