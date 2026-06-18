#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    bool flag = true;
    for (int axe = 1; axe <= n; axe++) {
        int i; cin >> i;
        if (a[i] != axe) flag = false;
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}