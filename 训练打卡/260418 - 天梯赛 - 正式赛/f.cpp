#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n = 11;
    string a = "";
    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        a += '0' + s.length();
    }
    cout << a;
    return 0;
}