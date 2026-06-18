#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
int main() {
    ios;
    int n; char x; cin >> n >> x;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s[x - 'A'] == 'o') flag = true;
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}