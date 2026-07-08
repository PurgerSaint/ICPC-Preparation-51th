#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (ans > a[i]) ans += a[i];
        else ans = a[i];
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t ? "\n" : "");
    return 0;
}

/*
3 2 1
3 5 1
3 1 6
1 4 6
*/

/*
3 1 4 2
3 1 2 6
1 4 2 6
1 2 6 6
*/

/*
6 2 5 1 4 3
2 8 5 1 4 3
2 5 13 1 4 3
2 5 1 14 4 3
2 5 1 4 18 3
2 5 1 4 3 21
*/

/*
2 5 1 4 3 6
2 1 6 4 3 6
1 3 6 4 3 6
1 3 4 10 3 6
1 3 4 3 13 6
1 3 4 3 6 19
1 3 3 7 6 19
1 3 3 6 13 19
*/

/*
1 4 3 2 5
1 3 7 2 5
1 3 2 9 5
1 3 2 5 14
1 2 5 5 14
*/

/*
1 4 3 5 2
1 4 3 2 7
1 4 2 5 7
1 2 6 5 7
1 2 5 11 7
1 2 5 7 16

1 3 7 5 2
1 3 5 12 2
1 3 5 2 14
1 3 2 7 14
1 2 5 7 14
*/

/*
4 1 3 2 5
1 5 3 2 5
1 3 8 2 5
1 3 2 10 5
1 3 2 5 15
*/

/*
2 7 1 6 3 5 4
2 1 8 6 3 5 4
2 1 6 14 3 5 4
2 1 6 3 17 5 4
2 1 6 3 5 22 4
2 1 6 3 5 4 26
*/