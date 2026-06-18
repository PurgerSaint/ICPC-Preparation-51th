#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(a.begin(), a.end(), greater<ll>());
    ll t = n - k, sum = 0;
    for (ll i = t; i < n; i++) {
        sum += a[i];
        if (sum >= x) {
            cout << (i + 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}

// c.cpp
/*
    有N个杯子，第i个杯子里装着A_i毫升液体
    N个杯子中只有K个杯子里面是酒，其余都是水，但不知道是哪K个
    你可以选择若干个（至少一个）杯子喝掉里面的液体，但要保证至少喝到X毫升清酒
    请问：最少选几个杯子？如果无法做到，输出-1

    1 <= k <= n <= 3*1e5
    1 <= a_i <= 1e9
    1 <= x <= 3*1e14
*/
// 第一次思考：是否是0/1背包（选与不选）？
//  // 即我是想枚举出所有方案，然后对每一种方案判断其所有情况都能满足x毫升酒
//  // 这个想法后面我想到找所有情况不如直接找最差，因为最差都能满足必定所有情况都能满足
//  // 但是我不懂最差情况下，如何安排哪些杯子是酒（因为都有可能）
// 第二次AI探讨：可以直接构造最优方案
//  // 为什么无法用0/1背包？每个杯子内部是酒还是水无法确定（背包前提是价值确定）
//  // 关键点：每种方案自然存在最坏情况，即前N-K杯容量最大的都是水
//  // 为何不用枚举？因为想要最少杯子数，必然是选择前m大的杯子，但是又不能少于N-K（不然可能都是水）