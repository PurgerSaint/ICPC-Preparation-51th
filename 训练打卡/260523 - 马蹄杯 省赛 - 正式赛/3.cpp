#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    string s; cin >> s;
    int cnt = 0;
    for (char c: s)
        if (c == '1')
            cnt++;
    ll x = 0, t = 1;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        x = (x + (s[i] - '0') * t) % cnt;
        t *= 2;
    }
    cout << (x + 1);
    return 0;
}