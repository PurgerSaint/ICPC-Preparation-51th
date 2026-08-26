#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve(vector<bool>& vis) {
    int n; cin >> n;
    n++;
    if (n > 2 && !(n % 2)) return "NO";
    return vis[n] ? "YES" : "NO";
}

int main() {
    ios;
    int t; cin >> t;
    vector<bool> vis(2 * 1e5 + 2, 1);
    for (int i = 3; i <= 2 * 1e5 + 1; i += 2) {
        if (vis[i]) {
            for (int j = 3; i * j <= 2 * 1e5 + 1; j += 2) {
                vis[i * j] = 0;
            }
        }
    } 
    while (t--) {
        cout << solve(vis);
        if (t) cout << "\n";
    }
    return 0;
}
