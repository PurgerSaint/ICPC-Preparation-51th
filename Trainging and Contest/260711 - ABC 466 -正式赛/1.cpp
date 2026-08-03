#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int m; cin >> m;
    vector<int> b(m);
    for (int& t: b) cin >> t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    for (int& t: a) {
        for (int j = 0; j < m; j++) {
            if (abs(t - b[j]) <= 1) {
                cnt++;
                b[j] = 1000;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}