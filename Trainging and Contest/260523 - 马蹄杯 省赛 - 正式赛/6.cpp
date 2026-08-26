#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, m, c; cin >> n >> m >> c;
        bool flag = false;
// 全为n的倍数
flag = flag || (c % n == 0);
// 同上，m的倍数
flag = flag || (c % m == 0);
// 一行以及其他列被异或的情况
flag = flag || c % (n - 1) == n - (c / (n - 1));
// 交叉，0101或1010的情况
flag = flag || c == ((m / 2) * (n / 2) + (m - m / 2) * (n - n / 2));
// 同上，情况二
flag = flag || c == ((m - m / 2) * (n / 2) + (m / 2) * (n - n / 2));
        cout << (flag ? "Yes" : "No") << (t != 0 ? "\n" : "");
    }
    return 0;
}

/*
    有n行m列的二维数组，全是0
    你可以执行如下任意一种操作若干次：
        1. 选择第i行(1<=i<=n)，将该行所有数字对1进行异或
        2. 选择第i列(1<=i<=m)，将该列所有数字对1进行异或
    问最终是否能得到恰好c个1？
*/