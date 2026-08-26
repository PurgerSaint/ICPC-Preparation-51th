#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    vector<string> s(3);
    for (string& t: s) cin >> t;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i][j] != s[2-i][2-j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}