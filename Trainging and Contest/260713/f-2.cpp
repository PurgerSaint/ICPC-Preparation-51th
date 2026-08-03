#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(a.begin(), a.end());
    if (k == 0) {
        cout << (a[0] > 1 ? 1 : -1);
        return 0;
    }
    if (n == k) {
        cout << a.back();
        return 0;
    }
    vector<ll> num, cnt;
    num.push_back(a[0]);
    cnt.push_back(1);
    for (int i = 1; i < n; i++) {
        if (a[i] != num.back()) {
            num.push_back(a[i]);
            cnt.push_back(1);
        } else cnt.back()++;
    }
    for (int i = 1; i < (int)cnt.size(); i++)
        cnt[i] += cnt[i - 1];
    auto it = lower_bound(cnt.begin(), cnt.end(), k);
    if (it != cnt.end() && (*it) == k)
        cout << num[it - cnt.begin()];
    else cout << -1;
    return 0;
}
