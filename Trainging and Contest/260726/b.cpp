#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

string solve() {
    int n, k; cin >> n >> k;
    if (n == 1 && k == 0) return "1";
    if (n - 2 < k) return "-1";
    string ans = "";
    int x = k / 2 + (k % 2), y = k / 2;
    // cout << x << " " << y << "\n";
    int r = n;
    if (x > 0) {
        ans += string(x + 1, '0');
        r -= x + 1;
    }
    if (y > 0 && x + y == k) {
        ans += string(y + 1, '1');
        r -= y + 1;
    }
    if (r > 0 && x > y) {
        ans = "1" + ans;
        r--;
    }
    for (int i = 1; i <= r; i++) {
        ans += (ans.empty() || ans.back() == '1' ? "0" : "1");
    }
    return ans;
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
