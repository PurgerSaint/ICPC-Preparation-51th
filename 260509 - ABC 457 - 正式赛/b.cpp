#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (vector<int>& t: a) {
        int sz; cin >> sz;
        for (int i = 0; i < sz; i++) {
            int val; cin >> val;
            t.push_back(val);
        }
    }
    int x, y; cin >> x >> y;
    cout << a[x - 1][y - 1];
    return 0;
}