#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n, m; cin >> n >> m;
    vector<ll> c(n);
    multiset<ll> v;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        v.insert(c[i]);
    }
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        vector<ll>& p = a[i];
        for (ll& t: p) cin >> t;
        sort(range(p), greater<ll>());
    }
    int ans = m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            while ((int)pq.size() > ans) {
                sum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() < ans) {
                sum += a[i][j];
                pq.push(a[i][j]);
            } else if (pq.top() < a[i][j]) {
                sum += a[i][j] - pq.top();
                pq.push(a[i][j]);
                pq.pop();
            }
            ll mn = *(v.begin());
            if (sum >= mn) {
                while ((int)pq.size() > 1 && sum - pq.top() >= mn) {
                    sum -= pq.top();
                    pq.pop();
                }
                ans = min(ans, (int)pq.size());
            }
        }
        v.erase(v.find(c[i]));
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}
