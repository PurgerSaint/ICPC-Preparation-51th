#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    vector<vector<int>> a(3, vector<int>(3, 0));
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 6; i++) {
            int t; cin >> t;
            if (t < 4 || t > 6) continue;
            a[j][t - 4]++; 
        }
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        double p = a[i][0] / 6.0;
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            double p_1 = (a[j][1] / 6.0) * p;
            for (int k = 0; k < 3; k++) {
                if (k == j || k == i) continue;
                double p_2 = (a[k][2] / 6.0) * p_1;
                sum += p_2;
            }
        }
    }
    printf("%.10lf", sum);
    return 0;
}

/*
    A的升级版，给与三个骰子每一面的数字，问使得三个骰子结果为4、5、6的结果概率是多少
    这题为什么不行呢？
*/