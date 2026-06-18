#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back({t, i});
    }
    sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y){
        return x.first < y.first;
    });
    for (int i = 0; i < 3; i++)
        cout << (a[i].second + 1) << (i != 2 ? " " : "");
    return 0;
}