#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
ll n, m;
vector<pair<ll, ll>> shop;

void solve() {
    string s(n, ' ');

    vector<vector<ll>> pre(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        ll& cost = shop[i - 1].first, val = shop[i - 1].second;
        for (int j = 0; j <= m; j++) {
            pre[i][j] = pre[i - 1][j];
            if (j >= cost)
                pre[i][j] = max(pre[i][j], pre[i - 1][j - cost] + val);
        }
    }

    vector<vector<ll>> suf(n + 2, vector<ll>(m + 2, 0));
    for (int i = n; i >= 1; i--) {
        ll& cost = shop[i - 1].first, val = shop[i - 1].second;
        for (int j = 0; j <= m; j++) {
            suf[i][j] = suf[i + 1][j];
            if (j >= cost)
                suf[i][j] = max(suf[i][j], suf[i + 1][j - cost] + val);
        }
    }

    ll vm = pre[n][m];

    for (int i = 1; i <= n; i++) {
        ll& cost = shop[i - 1].first, val = shop[i - 1].second;

        bool canSelect = false;
        for (int j = cost; j <= m; j++) {
            if (pre[i - 1][j - cost] + val + suf[i + 1][m - j] == vm) {
                canSelect = true;
                break;
            }
        }

        bool notSelect = false;
        for (int j = 0; j <= m; j++) {
            if (pre[i - 1][j] + suf[i + 1][m - j] == vm) {
                notSelect = true;
                break;
            }
        }

        s[i - 1] = ((canSelect && !notSelect)? 'A' : ((!canSelect && notSelect) ? 'C' : 'B'));
    }

    cout << s;
}

int main() {
    ios;
    cin >> n >> m;
    shop = vector<pair<ll, ll>>(n);
    for (pair<ll,ll>& p: shop)
        cin >> p.first >> p.second;
    solve();
    return 0;
}

// f.cpp
/*
    有N件商品，第i件商品的价格为P_i元,价值为V_i元
    只有M元，请问在所选商品总价不超过M元情况下，每种商品的属性如何？
        属性A：为了商品价值最大化，必选
        属性B：为了商品价值最大化，可选
        属性C：为了商品价值最大化，不能选
    输出每一种商品的属性

    1 <= N <= 5000
    1 <= M <= 5*1e4
    1 <= p_i <= m
    1 <= v_i <= 1e9
*/
// 第一次思考：这题也是用0/1背包，选或不选吗？（价值确定）
//  // f[i][j]为使用j元，购买前i个商品的最大价值
// 简化版题目：如何找到最大价值？
//  // 定义dp[i][j]同于之前的f[i][j]
//  // 对于每一个(i,j)，选择当前商品为dp[i-1][j-p_i]+v_i，不选为dp[i-1][j]
//  // 答案就是dp[n][m]
// 正确答案：双向DP
//  // 正向DP用于寻找第一个商品到当前第i个商品在满足消费不超过M下的最大价值
//  // 反向DP用于寻找当前第i个商品到最后一个商品在满足消费不超过M下的最大价值
//  //  // 正向DP可以得到全局最大价值VM
//  //  // 枚举预算[cost, m]，如果存在前i-1件商品能凑得的最大价值 + 后n-i件商品能凑得的最大价值 + 他本身价值 = 全局最大价值，那么他就是必选的
//  //  // 枚举预算[0, m]，如果存在前i-1件商品能凑得的最大价值 + 后n-i件商品能凑得的最大价值 = 全局最大价值，那么他就是不应该选的
//  //  // 前i-1件商品能凑得的最大价值可以用正向DP获得
//  //  // 后n-i件商品能凑得的最大价值可以用反向DP获得