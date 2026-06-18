/*
    给与N个数字构成的数组,然后有Q个问题,每个问题内有X和Y两个整数
    你要解决每个问题,输出数组中大于或等于X的不存在整数的第Y个
*/
#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
vector<ll> num;     // 数组本身
vector<ll> b;       // 数组中每个数在其之前缺失的整数个数

ll solve() {
    ll x, y;
    cin >> x >> y;

    // 找第一个大于或等于x的
    auto it = lower_bound(num.begin(), num.end(), x);
    // 找不到[x在所有数字后面]
    if (it == num.end()) return x + y - 1;

    ll pos = it - num.begin();  // pos 为当前*(it)已有的数组个数
    ll bx = (x - 1) - pos;      // x前面的数字(排除数组已有)
                                // x - 1 为x前面已有的数字
    ll k = bx + y;              // 第y个整数真正所在的位置

    auto itb = lower_bound(b.begin(), b.end(), k);

    // 第y个整数不在数组范围内
    if (itb == b.end()) return num.back() + (k - b.back());

    // 在num[idx]之前
    int idx = itb - b.begin();
    return num[idx] - (b[idx] - k + 1);
        // b[idx] - k 是多出来的数字
        // +1 避免计入 num[idx]
}

int main() {
    ios;
    int n, q; cin >> n >> q;
    num = vector<ll>(n);
    b = vector<ll>(n);
    for (ll& t: num) cin >> t;
    sort(num.begin(), num.end());
    for (ll i = 0; i < n; i++)
        b[i] = num[i] - (i + 1);
    while (q--)
        cout << solve() << (q != 0 ? "\n" : "");
    return 0;
}

// D题是寻找数组不存在整数的“第Y个大于或等于X”的那个数
// 第一次我是虽然做了异常处理(x在数组后面),但后面忘了数字间隙,并且错误返回了数组中已有的数
//  // lower_bound - begin() 是计算下标非第几个
// 之后补题,第二次在GPT的代码下,真正地去计算了间隙,但是由于要遍历导致TLE
// 第三次在Gemini优化下,引入数组中每个数字前不存在数字的个数
//  // 然后通过不存在的整数快速得到结果