#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    vector<ll> b = a;
    sort(range(b));
    if (a == b) {
        cout << "yes\n" << "1 1";
        return 0;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = lower_bound(range(b), a[i]) - b.begin();
    }
    vector<vector<int>> ans;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != i || (i > 0 && a[i] < a[i - 1])) {
            if (!f) {
                ans.push_back({});
                f = 1;
            }
            ans.back().push_back(c[i]);
        } else f = 0;
    }
    /*for (vector<int>& p: ans) {
        for (int& t: p) cout << t << " ";
        cout << "\n";
    }*/
    if ((int)ans.size() > 1) {
        cout << "no";
        return 0;
    }
    vector<int>& p = ans[0];
    for (int i = 1; i < (int)p.size(); i++) {
        if (p[i] != p[0] - i) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes\n" << p.back() + 1 << " " << p.front() + 1;
    return 0;
}