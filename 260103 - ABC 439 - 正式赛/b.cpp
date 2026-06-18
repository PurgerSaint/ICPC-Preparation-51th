#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

bool solve(int n) {
    set<int> a;
    while (n != 1) {
        if (a.count(n)) return false;
        a.insert(n);
        int a = n % 10,
            b = n / 10 % 10,
            c = n / 100 % 10,
            d = n / 1000;
        int cal = (a * a) + (b * b) + (c * c) + (d * d);
        n = cal;
    }
    return true;
}

int main() {
    ios;
    int n; cin >> n;
    cout << (solve(n)? "Yes" : "No");
    return 0;
}

/*
    一个快乐数2026代表可以经过以下操作变成1：
        2026 = 2^2 + 0^2 + 2^2 + 6^2 = 44
        44 = 4^2 + 4^2 = 32
        32 = 3^2 + 2^2 = 13
        13 = 1^2 + 3^2 = 10
        10 = 1^2 + 0^2 = 1
    给与一个整数n(1<=n<=2026)，判断他是否是快乐数？
*/
// 为什么我这样暴力可以写这一题呢？