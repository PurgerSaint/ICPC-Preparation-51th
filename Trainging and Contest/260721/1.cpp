#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    ll n, k; cin >> n >> k;
    if (k == n) return 0;
    if (k > (n / 2 + 1)) return -1;
    int cnt = 0;
    ll l = 1, r = n;
    while (l <= n) {
        ll mid = l + (r - l) / 2;
        cnt++;
        if (mid == k || (r - mid) == k) return cnt;
        else if (mid > k) r = mid % 2 ? mid : (r - mid);
        else return -1; 
    }
    return -1;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve() << (tt ? "\n" : "");
    }
    return 0;
}