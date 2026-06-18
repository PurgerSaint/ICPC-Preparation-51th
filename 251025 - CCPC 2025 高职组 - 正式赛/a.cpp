#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n, s, t; cin >> n >> s >> t;
    if (s == t) cout << 1;
    else if (t > s) {
        int a = t - s, b = s + (n - t);
        if (a < b) cout << 1;
        else cout << 2;
    } else {
        int b = s - t, a = t + (n - s);
        if (a < b) cout << 1;
        else cout << 2;
    }
    return 0;
}