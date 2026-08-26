#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    string s; cin >> s;
    string ans = "", res = "AEIOUYaeiouy";
    for (char c: s) {
        if (res.find(c) != string::npos) continue;
        else {
            ans += '.';
            if (c >= 'A' && c <= 'Z') ans += 'a' + (c - 'A');
            else ans += c;
        }
    }
    cout << ans;
    return 0;
}