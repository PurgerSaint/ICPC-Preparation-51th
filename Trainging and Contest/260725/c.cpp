#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> p(n), q(n);
    for (int& t: p) cin >> t;
    for (int& t: q) cin >> t;
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;
    auto rank = [&](const vector<int>& a) {
        int rk = 0;
        vector<bool> vis(n + 1, 1); 
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j < a[i - 1]; j++)
                if (vis[j]) cnt++;
            rk += cnt * fact[n - i];
            vis[a[i - 1]] = 0;
        }
        return rk;
    };
    cout << max(0, rank(q) - rank(p) - 1);
    return 0;
}
