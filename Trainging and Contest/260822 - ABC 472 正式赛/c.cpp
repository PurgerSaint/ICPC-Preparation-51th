#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, m; ll k; cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> vis(n + 1, 0);
    ll sum = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.front() <= (i - m)) {
            sum -= a[q.front()];
            q.pop();
        }
        if (sum + a[i] <= k) {
            sum += a[i];
            q.push(i);
            cout << "Yes";
        } else cout << "No";
        if (i < n) cout << "\n";
        
        // cout << i << " " << sum << "\n";
        // cout << (sum <= k ? "Yes" : "No");
    }
    return 0;
}