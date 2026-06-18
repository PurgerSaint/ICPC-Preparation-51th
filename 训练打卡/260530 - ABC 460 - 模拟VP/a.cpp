#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m; cin >> n >> m;
    int cnt = 0;
    while (m) {
        int t = n % m;
        if (t == m) break;
        m = t;
        cnt++;
    }
    cout << cnt;
    return 0;
}