#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n; cin >> n;
    vector<int> a(n), p(n);
    map<int, vector<int>> mp, ma;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp[p[i]].push_back(i);
    }
    for (int& t: a) cin >> t;
    vector<int> loc(n, 0);

    for (int i = 0; i < n; i++) {
        if (!mp.count(a[i])) return false;
        loc[i] = mp[a[i]][0];
    }
    for (int i = 1; i < n; i++)
        if (loc[i - 1] > loc[i])
            return false;
    return true;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO");
        if (tt) cout << "\n";
    }
    return 0;
}