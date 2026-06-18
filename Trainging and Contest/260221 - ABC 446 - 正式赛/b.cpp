#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int n, m;
vector<bool> juice;

int solve() {
    int t; cin >> t;
    int res = 0;
    while (t--) {
        int g; cin >> g;
        if (!juice[g - 1] && res == 0) {
            res = g;
            juice[g - 1] = true;
        }
    }
    return res;
}

int main() {
    ios;
    cin >> n >> m;
    juice = vector<bool>(m, false);
    while (n--)
        cout << solve() << (n != 0 ? "\n" : "");
    return 0;
}