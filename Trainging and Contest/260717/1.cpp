#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int solve() {
    int n, cnt = 0; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    for (int i = 0; i + 1 < n; i++)
        if (a[i] + a[i + 1] == 7 || a[i] == a[i + 1]) cnt++, i++;
    return cnt;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        if (tt) cout << "\n";
    }
    return 0;
}

/*
1/6: 2,3,5,4
2/5: 1,3,4,6
3/4: 1,2,5,6
*/