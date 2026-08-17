#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    vector<int> dp(n, 0);
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    cout << *max_element(range(dp));
    return 0;
}