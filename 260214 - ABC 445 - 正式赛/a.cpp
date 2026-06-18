#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    string s; cin >> s;
    cout << (s.front() == s.back() ? "Yes" : "No");
    return 0;
}