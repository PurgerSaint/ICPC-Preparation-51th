#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    map<string, int> cnt;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char& c: s)
            if ('A' <= c && c <= 'Z')
                c = 'a' + (c - 'A');
        cnt[s]++;
        mx = max(mx, cnt[s]);
    }
    cout << mx;
    return 0;
}