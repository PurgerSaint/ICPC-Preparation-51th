#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;

    vector<vector<int>> idx(26);
    for (int i = 0; i < n; i++)
        idx[s[i] - 'a'].push_back(i);

    ll cnt = 0;
    for (vector<int>& id: idx) {
        if (id.empty()) continue;
        for (int& i: id) {
            auto it1 = lower_bound(id.begin(), id.end(), i - r);
            auto it2 = upper_bound(id.begin(), id.end(), i - l);
            if (it2 > it1) cnt += it2 - it1;
        }
    }
    cout << cnt;
    return 0;
}