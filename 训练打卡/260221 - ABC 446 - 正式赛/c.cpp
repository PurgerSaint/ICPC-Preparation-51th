#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n), b(n);
    queue<int> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t.push(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        while (!t.empty() && b[i] != 0) {
            int g = t.front();
            if (b[i] >= a[g]) {
                b[i] -= a[g];
                a[g] = 0;
                t.pop();
            } else {
                a[g] -= b[i];
                break;
            }
        }
        while (!t.empty() && i - t.front() >= d) {
            a[t.front()] = 0;
            t.pop();
        }
    }
    return accumulate(a.begin(), a.end(), 0);
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}