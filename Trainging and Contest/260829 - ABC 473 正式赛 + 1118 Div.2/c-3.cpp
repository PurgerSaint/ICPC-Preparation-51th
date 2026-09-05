#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

void solve() {
    int n, mx; cin >> n >> mx;
    vector<int> a(n);
    ll sum = 0;
    for (int& t: a) {
        cin >> t;
        sum += t;
    }
    sort(range(a));

    vector<int> cnt(mx + 1, 0);
    for (int& x: a) cnt[x]++;
    vector<int> s(mx + 1, 0);
    for (int i = 1; i <= mx; i++)
        s[i] = s[i - 1] + cnt[i];

    for (int k = 1; k <= mx; k++) {
        if (k >= 31) {
            cout << sum << (k < mx ? " " : "");
            continue;
        }
        ll pk = (1LL << k);
        if (pk >= mx) {
            cout << sum << (k < mx ? " " : "");
            continue;
        }
        ll mx_ans = 0;

        for (int x = 1; 1LL * x * pk <= mx; x++) {
            ll c_ans = 0;
            for (ll j = 1; j < pk && j * x <= mx; j++) {
                int l = static_cast<int>(j * x);
                int r = static_cast<int>(min(1LL * mx, (j + 1) * x - 1));
                c_ans += j * (s[r] - s[l - 1]);
            }
            int pos = static_cast<int>(pk * x);
            c_ans += pk * cnt[pos];
            c_ans += (pk - 1) * (s[mx] - s[pos]);
            mx_ans = max(mx_ans, c_ans);
        }
        cout << mx_ans << (k < mx ? " " : "");
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}