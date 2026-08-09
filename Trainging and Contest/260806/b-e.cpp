#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> win(n + 1, 0);
    for (int i = 1; i <= n; i++)
        win[i] = win[i - 1] + (s[i - 1] == 'o');
    vector<ld> pre(n + 1, 0);
    auto check = [&](ld p) -> bool {
        ld mn = 0.0, sum = 0.0;
        pre[0] = 0.0L;
        int t = 0;
        for (int r = 1; r <= n; r++) {
            if (s[r - 1] == 'o') sum += 1.0 - p;
            else sum -= p;
            pre[r] = sum;
            while (t + 1 < r && win[t + 1] <= win[r] - k) {
                t++;
                mn = min(mn, pre[t]);
            }
            if (win[r] >= k && mn <= pre[r]) return 1;
        }
        return 0;
    };
    ld l = 0.0L, r = 1.0L;
    for (int i = 0; i < 50; i++) {
        ld mid = (l + r) / 2.0L;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(15) << l;
    return 0;
}
