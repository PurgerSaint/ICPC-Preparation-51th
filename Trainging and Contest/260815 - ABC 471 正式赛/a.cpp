#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int a, b; cin >> a >> b;
    if (a + b == 9 || a - b == 9 || a * b == 9 || b * 9 == a) cout << "Nine";
    else cout << "Nein";
    return 0;
}