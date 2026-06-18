#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    string s, a = ""; cin >> s;
    for (char c: s)
        if (c >= '0' && c <= '9')
            a += c;
    cout << a;
    return 0;
}