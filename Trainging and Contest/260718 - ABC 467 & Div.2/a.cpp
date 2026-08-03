#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
const double eps = 1e-9;
bool check(double a, double b) {
    return abs(a - b) < eps || a - b > eps;
}

int main() {
    ios;
    int h, w; cin >> h >> w;
    double h1 = h / 100.0, t = (double)w / h1 / h1;
    // cout << h1 <<  " " << t << "\n";
    if (check(t, 25.0)) cout << "Yes";
    else cout << "No";
    return 0;
}