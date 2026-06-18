#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

ll distance(ll& j, ll& r) {
    if (j >= r) return 0;
    if (r % 2 == 0 && j % 2 != 0) return (r - j + 1) / 2;
    return (r - j) / 2;
}

int main() {
    ios;
    ll l, r, d, u; cin >> l >> r >> d >> u;
    ll cnt = 0;
    ll real_l = abs(l), real_r = abs(r);

    for (ll j = d; j <= u; j++) {
        ll real_j = abs(j);
        // 同侧
        if (l * r > 0) {
            ll rr = r, rl = l;
            if (l < 0)
                rr = real_l, rl = real_r;
            // j为偶数 且 j大于这个范围 则 范围内所有点都是黑的
            if (j % 2 == 0 && real_j >= rr) {
                cnt += rr - rl + 1;
            // j在范围内
            } else if (real_j >= rl && real_j <= rr) {
                // j为偶数
                if (j % 2 == 0)
                    // [l,j]的所有数 + (j, r]所有偶数
                    cnt += real_j - rl + 1 + distance(real_j, rr);
                // j非偶数    
                else
                    // 则只有(j, r]所有偶数
                    cnt += distance(real_j, rr);
            // j在范围小于该范围
            } else if (real_j <= rl)
                // 范围内所有偶数
                cnt += distance(rl, rr) + (rl % 2 == 0 ? 1 : 0);
        // 非同侧
        } else {
            // [l,-j)的所有偶数 + (j,r]的所有偶数 (均不包含j本身)
            cnt += distance(real_j, real_l) + distance(real_j, real_r);
            // j为偶数
            if (j % 2 == 0)
                // -j到j的所有数
                cnt += min(real_j, real_l) + min(real_j, real_r) + 1;
        }
    }
    
    cout << cnt;
    return 0;
}
