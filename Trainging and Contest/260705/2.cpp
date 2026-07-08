#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define low(c) c >= 'a' && c <= 'z'
#define upr(c) c >= 'A' && c <= 'Z'

int main() {
    ios;
    string s; cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (upr(s[i])) cnt++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt == n - 1) {
            if (upr(s[i]))
                s[i] = ('a' + (s[i] - 'A'));
            else s[i] = ('A' + (s[i] - 'a'));
        }
        cout << s[i];
    }
    return 0;
}