#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

struct state {
    int m, v;
    double b;
};

int main() {
    ios;
    int n, t; cin >> n >> t;
    vector<state> a(n);
    for (auto& [m, v, b]: a) {
        cin >> m >> v;
        b = (double)v / m;
    }
    sort(range(a), [](state& x, state& y){
        return x.b > y.b;
    });
    double ans = 0;
    for (auto& [m, v, b]: a) {
        if (t >= m) {
            ans += v;
            t -= m;
        } else {
            ans += b * t;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}
