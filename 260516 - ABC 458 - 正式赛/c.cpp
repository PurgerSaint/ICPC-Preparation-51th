#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    string s; cin >> s;
    ll cnt = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C')
            cnt += 1 + min(i, n - 1 - i);
    }
    cout << cnt;
    return 0;
}