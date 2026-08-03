#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    string s; cin >> s;
    int n = s.length();
    if (n == 1) return 1;
    map<char, int> mp;
    map<char, char> err;
    for(int i = 0; i < n; i++) {
        mp[s[i]]++;
        if (i + 1 < n && s[i] != '<' && s[i + 1] != '>') return -1;
    }
    if (mp['*'] == n || (s[0] == '>' && s[n - 1]== '<')) return -1;
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        a++;
    }
    int b = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<') break;
        b++;
    }
    if (!a && !b) return -1;
    return max(a, b);
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}