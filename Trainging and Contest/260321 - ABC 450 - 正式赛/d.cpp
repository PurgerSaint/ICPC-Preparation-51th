#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    set<ll> st;
    for (ll& t: a) {
        ll val; cin >> val;
        t = val % k;
        st.insert(t);
    }
    if (st.size() == 1) {
        cout << 0;
        return 0;
    }
    sort(a.begin(), a.end());
    deque<ll> q(a.begin(), a.end());
    ll ans = a[n - 1] - a[0];
    for (int i = 0; i < n; i++) {
        ll t = q.front() + k; q.pop_front();
        ans = min(ans, t - q.front());
        q.push_back(t);
    }
    cout << ans;
    return 0;
}
