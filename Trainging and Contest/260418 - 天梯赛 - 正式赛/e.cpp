#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    unordered_map<int, pair<int, int>> hash;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (b == 0) hash[a].first++;
        else hash[a].second++;
    }
    vector<int> ans;
    for (pair<const int, pair<int, int>>& p : hash)
        if (p.second.second == 0) ans.push_back(p.first);
    int sz = ans.size();
    if (ans.empty()) cout << "NONE";
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < sz; i++)
            cout << ans[i] << (i != sz - 1 ? " " : "");
    }
    return 0;
}