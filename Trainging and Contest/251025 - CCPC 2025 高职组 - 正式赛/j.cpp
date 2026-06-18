#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    string s; getline(cin, s);
    string t = "";
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'n' && s[i+1] == ' ') {
            t += "ng";
        } else t += s[i];
    }
    t += s[n-1];
    if (s[n - 1] == 'n') t += 'g';
    cout << t;
    return 0;
}