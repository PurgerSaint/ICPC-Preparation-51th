#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

bool check(ll target, const vector<ll>& a, int n, ll k) {
    ll req_ops = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < target) {
            ll diff = target - a[i];
            ll ops = (diff + i - 1) / i;
            req_ops += ops;
            if (req_ops > k) return false;
        }
    }
    return req_ops <= k;
}

int main() {
    ios;
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    ll nx = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nx = min(nx, a[i]);
    }
    
    ll left = nx;
    ll right = a[1] + k;
    ll ans = left;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid, a, n, k)) {
            ans = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    cout << ans;
    return 0;
}
/*
    给与长度为n的序列和一个整数k
    可以执行m次(m∈[0,k])，每次可以将A_i(1<=i<=n)加上i
    求得序列中最大的最小值是什么
*/