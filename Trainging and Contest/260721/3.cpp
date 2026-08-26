#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;
    for (int& t: c) cin >> t;
    
    int a_cnt = 0;
    for (int j = 0; j < n; j++) {
        bool f = 1;
        for (int t = 0; t < n; t++) {
            if (a[(j + t) % n] >= b[t]) {
                f = 0;
                break;
            }
        }
        if (f) a_cnt++;
    }
    int b_cnt = 0;
    for (int j = 0; j < n; j++) {
        bool f = 1;
        for (int t = 0; t < n; t++) {
            if (b[t] >= c[(j + t) % n]) {
                f = 0;
                break;
            }
        }
        if (f) b_cnt++;
    }
    return 1LL * a_cnt * b_cnt * n;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve() << (tt ? "\n" : "");
    }
    return 0;
}