#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define ll long long

int main() {
    ios;
    ll n; cin >> n;
    vector<ll> num;
    vector<int> vis(n + 1, 0);
    // 枚举每一个数的平方
    for (ll i = 1; i * i <= n; i++)
        num.push_back(i * i);
    ll size = num.size();
    // 每两个平方相加的和，存入并去重
    for (ll i = 0; i < size; i++)
        for (ll j = i + 1; j < size; j++) {
            ll t = num[i] + num[j];
            if (t > n) break;
            vis[t]++;
        }
    size = count(vis.begin(), vis.end(), 1);
    cout << size << "\n";
    ll cnt = 0;
    for (ll i = 0; i < n + 1; i++) {
        if (vis[i] != 1) continue;
        cnt++;
        cout << i << (cnt != size ? " " : "");
    }
    return 0;
}
// Q3: 这样可以了，但请问还有什么更优雅的解法吗？
// Q2: 不行，还是错误
// Q1: 为什么我枚举了所有数字的平方，然后两两相加，虽然交上去不超时，但是错了很多，为什么呢？

/*
合数是指大于 1 且存在除 1 与自身外因子的自然数。
由婆罗摩笈多–斐波那契恒等式可知，若x = a^2 + b^2，y = c^2 + d^2，
则 xy 亦可表示为平方和，且至少存在两种不同的构造方式。
因此，若整数 a 为合数，且可表示为平方和的乘积，则必然存在多组
(x,y) 使得 x^2 + y^2 = a，与题目所要求的唯一性矛盾，故 a 必须为质数。
又由费马平方和定理可知，一个奇质数可以表示为两个整数平方和，当且仅当其模 4 取余为 1。
综上，题目中的好整数必定是模 4 取余为 1 的奇质数。
*/