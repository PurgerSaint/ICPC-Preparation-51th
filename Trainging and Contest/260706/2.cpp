#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

void turn(char& c, bool f) {
    int nw = c - '0', nt = 9 - nw;
    if (nt >= nw) return;
    if (f && nt == 0) return;
    c = '0' + nt;
}

int main() {
    ios;
    string s; cin >> s;
    turn(s[0], true);
    int n = s.length();
    for (int i = 1; i < n; i++) {
        turn(s[i], false);
    }
    cout << s;
    return 0;
}