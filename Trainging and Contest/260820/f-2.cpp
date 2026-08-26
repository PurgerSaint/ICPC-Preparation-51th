#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int n;
vector<vector<int>> res;
void dfs(vector<ll>& a, vector<int>& path, int i, ll x) {
    if (x == 0) {
        res.push_back(path);
        return;
    }
    if (x < 0 || i >= (int)a.size()) return;
    path.push_back(i);
    dfs(a, path, i + 1, x - a[i]);
    path.pop_back();
    dfs(a, path, i + 1, x);
}

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<int> path;
    dfs(a, path, 0, 2559447046);
    for (vector<int>& p: res) {
        for (int& i: p) cout << i << " ";
        cout << "\n";
    }
    sort(range(a), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cout << sum << (i < n - 1 ? " " : "");
    }
    return 0;
}