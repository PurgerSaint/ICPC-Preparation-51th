#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
string s;
int n;

void solve() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        vector<int> ct(3, 0);
        for (int j = i; j < n; j++) {
            char ch = s[j];
            ct[ch - 'A']++;
            if (ct[1] < ct[0]) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    ios;
    cin >> n >> s;
    solve();
    return 0;
}