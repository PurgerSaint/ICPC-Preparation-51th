#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int n;
vector<ll> a;
vector<vector<int>> mp;
unordered_map<ll, int> freq;
vector<bool> rut;
vector<bool> vis;
int dup_cnt = 0;

void dfs(int node, int cnt) {

    freq[a[node]]++;
    vis[node] = true;

    if (freq[a[node]] >= 2) dup_cnt++;
    rut[node] = dup_cnt > 0;

    for (int& v: mp[node])
        if (!vis[v])
            dfs(v, cnt + 1);

    if (freq[a[node]] >= 2) dup_cnt--;
    freq[a[node]]--;
}

int main() {
    cin >> n;
    mp = vector<vector<int>>(n);
    a = vector<ll>(n);
    rut = vector<bool>(n, false);
    vis = vector<bool>(n, false);
    for (ll& t: a) cin >> t;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        mp[u - 1].push_back(v - 1);
        mp[v - 1].push_back(u - 1);
    }

    dfs(0, 1);

    for (int i = 0; i < n; i++) {
        cout << (rut[i] ? "Yes" : "No") << (i != n - 1 ? "\n" : "");
    }
    return 0;
}
// d.cpp
/*
    有n个点构成的一棵树,每个点有一个数A_i(1<=A_i<=1e9),给你所有边(u_i指向v_i)
    问对于从点1到每个点k(1<=k<=n)的简单路径,是否会在有两个不同点的情况下有两个相同的数,是就输出Yes否就No

    [第1次思考 WA]用dfs从根节点遍历,然后对每个节点用set记录遇到的整数,最后可得到结果
    [补题:第2次思考 WA]因为是值引用,多个值可能相同,需要进行回溯
    [补题:第3次思考 WA]不用记录路径,可能会导致值复制的MLE,直接记录对应值出现次数,然后回溯即可
*/