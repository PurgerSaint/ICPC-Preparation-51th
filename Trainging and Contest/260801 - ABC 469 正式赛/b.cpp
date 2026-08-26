#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    if (n == 1) {
        cout << (s[0] == 'x');
        return 0;
    }
    if (s.size() >= 2 && s[0] == 'x' && s[1] == 'x') cnt++;
    if (s.size() >= 2 && s[n - 1] == 'x' && s[n - 2] == 'x') cnt++;
    if (s.size() >= 3) {
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == 'o') continue;
            if (s[i - 1] == 'o') continue;
            if (s[i + 1] == 'o') continue;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}