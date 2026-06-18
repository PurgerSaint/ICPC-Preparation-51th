#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    /*
    int res = 1;
    原方法
    for (int i = 1; i <= n; i++)
        res *= 2;
    cout << (res - 2 * n);
    */
    // 1LL代表为long long类型的1
    // 即位运算(1LL << n)的结果也必定是long long(防溢出)
    cout << ((1LL << n) - (n << 1));
    return 0;
}

/*
    给与一个整数N，计算2^N - 2*N的结果
*/