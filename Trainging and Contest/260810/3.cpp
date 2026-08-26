#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

const int MOD = 1e9 + 7;
const int MAXN = 500000;
vector<int> spf(MAXN + 1);

void init() {
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            if ((ll)i * i <= MAXN) {
                for (int j = i * i; j <= MAXN; j += i)
                    if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

int solve() {
    int n, x; cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        while (v > 1) {
            mp[spf[v]]++;
            v /= spf[v];
        }
    }
    ll ans = 1;
    for (auto& [num, cnt]: mp)
        ans = mod(ans * (cnt + 1), MOD);
    return ans;
}

int main() {
    ios;
    init();
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}
