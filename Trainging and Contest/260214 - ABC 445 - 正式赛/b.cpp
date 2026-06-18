#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<string> a(n);
    int mx = 0;
    for (string& s: a) {
        cin >> s;
        mx = max(mx, (int)s.length());
    }
    for (int i = 0; i < n; i++) {
        string& s = a[i];
        int t = mx - (int)s.length();
        for (int x = 0; x < (t / 2); x++)
            cout << '.';
        cout << s;
        for (int x = 0; x < (t / 2); x++)
            cout << '.';
        if (i != n - 1) cout << "\n";
    }
    return 0;
}