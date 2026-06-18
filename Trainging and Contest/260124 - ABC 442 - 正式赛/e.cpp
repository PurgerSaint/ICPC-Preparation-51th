// e.cpp
/*
    给与N个怪物的坐标(x_i,y_i)
    然后给与Q个方案，每个方案给与起始怪物X和终点怪物Y
    从原点起始有一道激光，在每个方案中，激光先面向X然后顺时针移动到面向Y
    被激光经过的所有怪物都会死亡，请问每个方案可以消灭多少个怪物？
*/
// 初步尝试：把每个怪物都转为斜率，起始怪物和终点怪物都可以用二分计算对应象限内的怪物，其余顺时针经过的都可以之间加
//  //  第一次修改：忘记坐标轴上也有怪物
//  //  第二次修改：重构为八个象限（四个坐标轴+四个象限）
//  //  第三次修改：第二象限斜率递增，其余递减
// GPT修改：斜率没法量化每个怪物的位置，应该使用极角（将位置转为[0,2π]）
//  // acosl(-1.0L)为最稳妥写π的方法
#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ld = long double;
const ld PI = acosl(-1.0L);

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<ld> d, a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        ld ang = atan2(y, x);
        if (ang < 0) ang += 2 * PI;
        d.push_back(ang);
        a[i] = ang;
    }

    sort(d.begin(), d.end());

    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        
        int cnt = 0;
        if (a[x] >= a[y]) {
            cnt = upper_bound(d.begin(), d.end(), a[x]) - lower_bound(d.begin(), d.end(), a[y]);
        } else {
            cnt = (d.end() - lower_bound(d.begin(), d.end(), a[y])) + (upper_bound(d.begin(), d.end(), a[x]) - d.begin());
        }
        cout << cnt << (i != q ? "\n" : "");
    }
    
    return 0;
}