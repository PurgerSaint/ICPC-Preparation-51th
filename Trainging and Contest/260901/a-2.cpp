#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(range(a));
    int cnt = 0;
    ll pre = 0;
    for (int i = 0; i < n; i++) {
        if (pre > a[i]) continue;
        pre += a[i];
        cnt++;
    }
    cout << cnt;
    return 0;
}