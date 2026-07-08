#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            mp[i - t]++;
        }
        ll cnt = 0;
        for (auto const& [val, count]: mp) {
            if (count >= 2)
                cnt += (ll)count * (count - 1) / 2;
        }
        cout << cnt << (tt ? "\n" : "");
    }
    return 0;
}

/*
给与 $t(1<=t<=10^4)$ 组长度为 $n_{k}(1<=k<=t, 1<=n_{k}<2\times 10^5)$ 的数组 $a$，寻找每个数组 $a$ 中符合条件的 $(i,j)$ 的数量:
- $1<=i<j<=n_{k}$ 且 $a_{j} - a_{i} = j - i$
*/