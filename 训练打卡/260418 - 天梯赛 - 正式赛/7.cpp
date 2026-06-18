#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0;
    int mx = 0, mn = INT_MAX;
    for (int& t : a) {
        cin >> t;
        sum += t;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    sum = sum / n;
    cout << mx << " " << mn << " " << sum << "\n";
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (a[i] > sum * 2)
            ans.push_back(i + 1);
    if (ans.empty()) cout << "Normal";
    else {
        int sz = ans.size();
        for (int i = 0; i < sz; i++)
            cout << ans[i] << (i != sz - 1 ? " " : "");
    }
    return 0;
}