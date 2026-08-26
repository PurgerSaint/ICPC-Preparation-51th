#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    string s; cin >> s;
    int e = 0, w = 0;
    for (char c: s)
        if (c == 'E') e++;
        else w++;
    cout << (w > e ? "West" : "East"); 
    return 0;
}