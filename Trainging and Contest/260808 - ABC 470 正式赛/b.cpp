#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (b.empty() || !mp.count(t)) {
            mp[t] = b.size();
            b.push_back({t, 1});
        } else b[mp[t]].second++;
    }
    sort(range(b), [](pair<int, int>& x, pair<int, int>& y){
        return x.second < y.second;
    });
    cout << n - b.back().second;
    return 0;
}
