#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> x(n + 1);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        x[l].push_back(r);
    }
    for (vector<int>& p: x)
        sort(p.begin(), p.end());
    int cnt = 0, mx = -1;
    for (vector<int>& p: x) {
        if (mx == -1 && !p.empty()) {
            mx = p.front();
            cnt++;
        } else if (mx != -1 && p.front() < mx) {
            mx = p.front();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}