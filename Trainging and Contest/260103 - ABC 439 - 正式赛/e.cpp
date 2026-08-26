#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define ll long long

ll solve(vector<pair<ll, ll>>& a) {
    ll n = a.size();
    if (n <= 1) return n;
    vector<ll> top;
    top.push_back(a[0].second);
    for (pair<ll, ll>& p: a) {
        if (p.second > top.back()) top.push_back(p.second);
        else {
            auto it = lower_bound(top.begin(), top.end(), p.second);
            *(it) = p.second;
        }
    }
    return top.size();
}

int main() {
    ios;
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (pair<ll, ll>& t: a)
        cin >> t.first >> t.second;
    sort(a.begin(), a.end(), [](pair<ll, ll>& x, pair<ll, ll>& y){
        return x.first == y.first ? x.second > y.second : x.first < y.first;
    });
    cout << solve(a);
    return 0;
}

/*
    给与N个坐标点(a, b)，x轴代表平面，y轴代表高度
    人i在点(A_i, 0)处，试图在(B_i, 1)放风筝
    人i和j不能同时放风筝的条件为：
        连接点 (A _i ,0) 和 (B_i ,1) 的线段与连接点 (A_j​ ,0) 和 (B_j ,1) 的线段有一个交点。(包括线段端点相切的情况)
    问最多有多少人可以同时放风筝？
*/
// Q1: 为什么这题无法解决，甚至样例输入都不行？
// A1: 俄罗斯套娃，最长上升子序列LIS模版题