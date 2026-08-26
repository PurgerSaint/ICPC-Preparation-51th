#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> cnt_n(n, 0), cnt_m(m, 0); 
    vector<string> s(n);
    for (string& t: s) cin >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                cnt_n[i]++;
                cnt_m[j]++;
            }
        }
    }
    vector<int> ni, mj;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (!flag && cnt_n[i] == m) continue;
        flag = true;
        ni.push_back(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (cnt_n[i] < m) break;
        ni.pop_back();
    }
    flag = false;
    for (int j = 0; j < m; j++) {
        if (!flag && cnt_m[j] == n) continue;
        flag = true;
        mj.push_back(j);
    }
    for (int j = m - 1; j >= 0; j--) {
        if (cnt_m[j] < n) break;
        mj.pop_back();
    }
    for (int& i: ni) {
        for (int& j: mj) {
            cout << s[i][j];
        }
        if (ni.back() != i)
            cout << "\n";
    }
    return 0;
}