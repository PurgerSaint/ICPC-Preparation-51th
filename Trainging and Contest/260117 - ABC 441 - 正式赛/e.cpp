#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
string s;
int n;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

void solve() {
    vector<int> num = {1, -1, 0};
    vector<int> pre(n, 0);
    pre[0] = num[s[0] - 'A'];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + num[s[i] - 'A'];
    }

    ll cnt = 0;
    ordered_multiset as;
    as.insert({0, -1});
    for (int i = 0; i < n; i++) {
        cnt += as.order_of_key({pre[i], -1e9});
        as.insert({pre[i], i});
    }
    cout << cnt;
}

int main() {
    ios;
    cin >> n >> s;
    solve();
    return 0;
}

// e.cpp
/*
    给一个长度为n、仅包含ABC字符的字符串s
    问满足A字符数量大于B字符数量的连续子串个数
    字符串内容相等但位置不同也是不同字符串
*/
// 第一次思考：暴力统计，统计A和B字符数量，n*(n-1)进行遍历枚举，结果超时
// 第二次思考：将每个字符转为贡献（A为1，B为-1，C为0）进行计算，那么连续子串就是前缀和之差
//  // 引入PBDS，快速查找比当前数小的那个