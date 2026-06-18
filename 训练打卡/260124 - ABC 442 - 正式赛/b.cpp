#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int n = 0;
bool flag = false;

string solve() {
    int a; cin >> a;
    if (a == 1) n++;
    else if (a == 2 && n >= 1) n--;
    else if (a == 3) flag = !flag; 
    return n >= 3 && flag ? "Yes" : "No";
}

int main() {
    ios;
    int q; cin >> q;
    while (q--)
        cout << solve() << (q != 0 ? "\n" : "");
    return 0;
}