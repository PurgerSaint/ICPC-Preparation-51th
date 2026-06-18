#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    unordered_map<int, vector<int>> hash;
    vector<int> mark;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        mx = max(mx, val);
        if (!hash.count(val)) mark.push_back(val);
        hash[val].push_back(i);
    }
    sort(mark.begin(), mark.end());
    int sz = hash[mx].size();
    for (int i = 0; i < sz; i++) {
        cout << hash[mx][i] << (i != sz - 1 ? " " : "\n");
    }
    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        auto it = upper_bound(mark.begin(), mark.end(), x);
        if (it == mark.end()) cout << 0;
        else cout << hash[*it].front();
        if (m != 0) cout << "\n";
    }
    return 0;
}