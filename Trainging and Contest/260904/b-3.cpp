#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    int n; ll d; cin >> n >> d;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    multiset<ll> st;
    ll ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        auto it = st.lower_bound(a[r]);
        while ((it != st.end() && *it - a[r] < d) || (it != st.begin() && a[r] - *prev(it) < d)) {
            st.erase(a[l++]);
            it = st.lower_bound(a[r]);
        }

        ans += (r - l + 1);
        st.insert(a[r]);
    }
    cout << ans;
    return 0;
}