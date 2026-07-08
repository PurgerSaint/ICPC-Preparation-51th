#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int x, n; cin >> x >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int>& t: a)
        cin >> t.first >> t.second;
    sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y){
        return x.first > y.first;
    });
    while (!a.empty() && a.back().first < x) {
        x += a.back().second;
        a.pop_back();
    }
    cout << (a.empty() ? "YES" : "NO");
    return 0;
}