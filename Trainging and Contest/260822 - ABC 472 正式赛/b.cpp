#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    suf[n] = a[n];
    for (int i = n - 1; i > 0; i--)
        suf[i] = suf[i + 1] + a[i];
    ll ans = 1LL << 60;
    for (int i = 1; i < n; i++)
        ans = min(ans, abs(pre[i] - suf[i + 1]));
    cout << ans;
    return 0;
}