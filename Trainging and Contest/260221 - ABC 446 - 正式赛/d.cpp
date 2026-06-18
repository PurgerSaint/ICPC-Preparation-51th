#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<int> res(n, 1), a(n);
    unordered_map<int, vector<int>> hash;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (hash.count(a[i] - 1)) {
            vector<int>& t = hash[a[i] - 1];
            for (int& j: t) {
                res[i] = max(res[i], res[j] + 1);
            }
        }
        hash[a[i]].push_back(i);
        mx = max(mx, res[i]);
    }
    cout << mx;
    return 0;
}