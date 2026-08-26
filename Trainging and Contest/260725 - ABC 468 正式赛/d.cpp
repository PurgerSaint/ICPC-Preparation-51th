#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    string s; cin >> s;
    ll ans = 0;
    int n = s.length();
    for (int c = 0; c < n; c++) {
        int bad = 0;
        int l = c, r = c;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) bad++;
            if (bad > 1) break;
            ans++;
            l--, r++;
        }
    }
    for (int c = 0; c < n; c++) {
        int bad = 0;
        int l = c, r = c + 1;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) bad++;
            if (bad > 1) break;
            ans++;
            l--, r++;
        }
    }
    cout << ans;
    return 0;
}
