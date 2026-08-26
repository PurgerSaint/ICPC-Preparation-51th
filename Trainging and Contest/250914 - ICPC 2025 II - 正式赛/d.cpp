#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 998244353;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
vector<ll> a;
vector<vector<ll>> res;
void dfs(int i, int n, vector<ll>& path) {
    if (i == n) {
        return;
    }
    path.push_back(a[i]);
    res.push_back(path);
    dfs(i + 1, n, path);
    path.pop_back();
    dfs(i + 1, n, path);
}
ll solve() {
    int n; cin>>n;
    a = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> path;
    dfs(0, n, path);
    ll sum = 0;
    for (vector<ll>& p : res) {
        int size = p.size();
        if (size != 1) {
            for (int i = size - 1; i > 0; i--) {
                for (int j = 0; j < i; j++)
                    p[j] = (p[i] + p[j]) % MOD;
            }
        }
        sum += (p[0] % MOD);
    }
    return sum;
}
int main() {
    IOS;
    int t; cin>>t;
    while(t--) {
        cout << solve() << (t != 0 ? "\n" : "");
    }
    return 0;
}