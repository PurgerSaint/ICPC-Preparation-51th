#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 1 && s[0] == 'b') {
        return false;
    }
    for (int i = n % 2; i + 1 < n; i+=2)
        if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1])
            return false;
    return true;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << (tt ? "\n" : "");
    }
    return 0;
}