#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    string x, y;
    vector<int> a(26, 0), b(26, 0);
    cin >> x >> y;
    for (char c: x) a[c - 'a']++;
    for (char c: y) b[c - 'a']++;
    int t; cin >> t;
    ll sx = x.size(), sy = y.size(), ss = sx + sy;
    auto check = [&](ll index, char c) -> ll {
        if (index == sx - 1) return a[c - 'a'];
        if (index == ss - 1) return a[c - 'a'] + b[c - 'a'];
        ll cnt = 0;
        if (index < sx) {
            for (int i = 0; i <= index; i++)
                if (x[i] == c)
                    cnt++;
        } else if (index == sx) cnt = a[c - 'a'] + (y[0] == c ? 1 : 0);
        else if (index < (sx + (sy - 1))) {
            cnt += a[c - 'a'];
            index -= sx + 1;
            for (int i = 0; i <= index; i++)
                if (y[i] == c)
                    cnt++;
        }
        return cnt;
    };
    while (t--) {
        ll l, r; char c;
        cin >> l >> r >> c;
        ll ls = l % ss, rs = r % ss;
        ll t = (r / ss) + (l / ss + (ls == 0 ? 0 : 1));
        
        ll sum = 0;
        if (l == r) {
            for (int i = l - 1; i < sx; i++) if (x[i] == c) sum++;
            for (int i = 0; i < r - 1; i++) if (y[i] == c) sum++;
        } else sum = t * (a[c - 'a'] + b[c - 'a']) + check(ls, c) + check(rs, c);
        cout << sum << (t != 0 ? "\n" : "");
    }
    return 0;
}
/*
    给定字符串X和Y,定义字符串序列S_1,S_2,...如下：
        S_1 = X
        S_2 = Y
        对于i>=3,S_i是由S_{i-1}和S_{i-2}按此顺序连接而成的
    对于每个i=1,2,...,Q,回答以下问题:
        给定整数L_i、R_i和字符C_i,求字符C_i在S_{10^18}的第L_i个字符到第R_i个字符中出现的次数

    [比赛:第一次思考]对于每个L和R,答案由L和R之间有多少个整体字符串、L所在字符串个数和R所在个数,但我忘了拼接次序
*/