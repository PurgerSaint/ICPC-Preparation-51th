// c.cpp
/*
    最初有N个排列成一行的白色方格，给与每个方格涂黑的成本
    将一些方块涂成黑色的步骤：
        选取任意正整数x，使得对于第i个方格(1 <= i <= N)满足"当(i + x)除以2w的余数小于w"时可以涂黑
    找出执行此操作所需的最低总成本
*/
#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define ll long long

class different {
    vector<ll> diff;
    int n;

    public:
        different(int t): n(t) {
            diff = vector<ll>(t + 1, 0);
        }

        void inic(int i, int j, int val) {
            if (i > j) return;
            diff[i] += val;
            if (j + 1 < n) diff[j + 1] -= val;
        }

        vector<ll> result() const {
            vector<ll> res(n);
            res[0] = diff[0];
            for (size_t i = 1; i < n; i++)
                res[i] = res[i - 1] + diff[i];
            return res;
        }
};

ll solve() {
    int n, w; cin >> n >> w;
    int w2 = 2 * w;
    different d(w2);
    // 枚举每一个坐标[1,n]
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        int t = i % w2;
        
        int l = (w2 - (i % w2)) % w2;
        int r = (l + w - 1) % w2;

        if (l > r) {
            d.inic(0, r, val);
            d.inic(l, w2 - 1, val);
        } else
            d.inic(l, r, val);
    }
    vector<ll> res = d.result();
    return *min_element(res.begin(), res.end());
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t != 0 ? "\n" : "");
    return 0;
}
// 第一次虽然知道每一次成本必然(从某一个方格开始)连续(通过草稿模拟),但还是逐步枚举x,直接超时
//  // 我想着用二分,但我要计算所得并非有序,即没有趋势(纵使要最小)
//  // DP也是同理,在模拟时找不到子问题和通过子问题推举出最终问题(找不到状态方程)
//  // 于是枚举每一个i在[1, w2]，从而超时
// 第二次的想法是枚举每一个坐标，然后枚举余数[0,w-1]，记录每一次坐标所在区间的总和
//  // 用差分数组完成，因为他是对连续的一段区间进行操作(都加上他本身)
//  // 但输出还是错误，因为这些区间不一定连续，即坐标内可能存在多个符合条件的区间(区间长度均为w)
// 第三次采取了AI的方法，把差分数组当做是枚举x下的每一种总和
//  // 然后就枚举每一个坐标i，得到符合的x区间，对这些区间进行操作，因为当x符合条件时，当前坐标值才会被加入