#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n; cin >> n;
    vector<int> a(n * 2);
    vector<int> cnt(2 * n + 1, 0);
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> b = a;
    sort(range(b));
    b.erase(unique(range(b)), b.end());
    int x = 0, y = 0, z = 0;
    for (int& t: b) {
        if (cnt[t] % 2) x++;
        else if (cnt[t] % 4) y++;
        else z++;
    }
    int ans = x + 2 * y + 2 * z;
    if (z % 2 && x == 0) ans -= 2;
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
