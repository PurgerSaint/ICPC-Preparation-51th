#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int l1 = 0;
    vector<int> r1;
    int a1 = 0, b1 = 0, c1 = 0;
    for (int i = l1; i < n - 2; i++) {
        switch (a[i]) {
            case 1: a1++; break;
            case 2: b1++; break;
            case 3: c1++; break;
        }
        if (a1 >= b1 + c1) {
            r1.push_back(i);
        }
    }
    if (r1.empty()) return false;
    for (int& r: r1) {
        int l2 = r + 1;
        int a2 = 0, b2 = 0, c2 = 0;
        for (int i = l2; i < n - 1; i++) {
            switch (a[i]) {
                case 1: a2++; break;
                case 2: b2++; break;
                case 3: c2++; break;
            }
            if (a2 + b2 >= c2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << (tt ? "\n" : "");
    }
    return 0;
}