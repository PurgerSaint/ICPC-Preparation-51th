#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    map<int, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        mp1[t] = i;
        mp2[i] = t;
    }
    bool v = 1;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            map<int, int>& val_map = v ? mp1 : mp2;
            map<int, int>& loc_map = v ? mp2 : mp1;
            int val_x = loc_map[x], val_y = loc_map[y];
            // cout << x << "->" << val_x << " " << y << "->" << val_y << "\n";
            val_map[val_x] = y;
            val_map[val_y] = x;
            loc_map[y] = val_x;
            loc_map[x] = val_y;
        } else {
            v = !v;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (v ? mp2[i] : mp1[i]) << (i < n ? " " : "");
    return 0;
}
