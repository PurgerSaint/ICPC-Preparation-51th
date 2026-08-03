#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t >= 0) f = 1;
    }
    cout << (f ? "No" : "Yes");
    return 0;
}