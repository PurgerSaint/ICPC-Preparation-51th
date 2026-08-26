#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    string s; cin >> s;
    int sum = 0;
    for (char c: s)
        if (c == 'i' || c == 'j')
            sum++;
    cout << sum;
    return 0;
}