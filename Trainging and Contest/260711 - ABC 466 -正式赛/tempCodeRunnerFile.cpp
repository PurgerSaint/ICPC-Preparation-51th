#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        cout << "? " << i << " " << (i + 1) << endl;
        string s; cin >> s;
    }
    cout << "!" << (n - 1) << endl;
    return 0;
}