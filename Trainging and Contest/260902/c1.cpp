#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int solve() {
    ll x, m;
    cin >> x >> m;
    set<ll> st;
    for (ll d = 1; d <= 2 * x; d++) {
        ll y = x ^ d;
        if (y % d == 0 && y > 0 && y <= m) st.insert(y);
    }
    return st.size();
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}

/*
10
01  1
11  3   x

10
10  2
0   0   x

10
11  3
01  1

==============
5 7
101
111 7
010 2   x

101
110 6
011 3

101
101 5
0   0   x

101
100 4
001 1

101
011 3
010 2   x

101
010 2
111 7   x

101
001 1
100 4   x

============
6 9
0110
1001    9
1111    15  x

0110
1000    8
1110    14  x

110
111 7
001 1

110
110 6
0   0   x

110
101 5
011 3

110
100 4
010 2

110
011 3
111 7   x

110
010 2
100 4   x

110
001 1
111 7   x
*/