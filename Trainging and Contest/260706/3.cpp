#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<pair<string, int>> a;
    map<string, int> mp;
    while (n--) {
        string s; cin >> s;
        if (!mp.count(s)) {
            a.push_back({s, 0});
            mp[s] = a.size() - 1;
        }
        a[mp[s]].second++;
    }
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        return x.second > y.second;
    });
    cout << a[0].first;
    return 0;
}