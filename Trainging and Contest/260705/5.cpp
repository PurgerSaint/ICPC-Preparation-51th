#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int mv(int& nw, int& nt, int& len) {
    if (nt >= nw) return nt - nw;
    return nt + (len - nw);
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    ll ans = 0;
    int loc = 1;
    while (m--) {
        int a; cin >> a;
        ans += mv(loc, a, n);
        loc = a; 
    }
    cout << ans;
    return 0;
}