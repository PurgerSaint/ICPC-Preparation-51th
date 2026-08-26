#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n * 2);
        for (int& t: a) cin >> t;

        auto check = [&](int l, int r) -> int {
            set<int> s;
            for (int i = 0; i <= n; i++)
                s.insert(i);

            while (l >= 0 && r < 2 * n && a[l] == a[r]) {
                s.erase(a[l]);
                l--, r++;
            }
            return *s.begin();
        };

        vector<int> z;
        for (int i = 0; i < 2 * n; i++) {
            if (!a[i]) {
                z.push_back(i);
                if (z.size() == 2) break;
            }
        }
        int ans = max(check(z[0], z[0]), max(check(z[1], z[1]), check((z[0] + z[1]) / 2, (z[0] + z[1] + 1) / 2)));
        cout << ans << (tt ? "\n" : "");
    }
    return 0;
}