#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    int mx = -1;
    for (int& t: a) {
        cin >> t;
        mx = max(mx, t);
    }
    sort(a.begin(), a.end());
    string res = "";
    int add = 0;
    for (int i = 1; i <= mx; i++) {
        int num = a.end() - lower_bound(a.begin(), a.end(), i) + add;
        res = to_string(num % 10) + res;
        add = num / 10;
    }
    if (add != 0)
        res = to_string(add) + res;
    cout << res;
    return 0;
}