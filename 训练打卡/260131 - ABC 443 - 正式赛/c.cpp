#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n;ll time; cin >> n >> time;
    if (n == 0) {
        cout << time;
        return 0;
    }
    ll last = 0, cost = 0;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        if (val >= last) {
            cost += val - last;
            last = val + 100;
        }
    }
    if (time > last) {
        cost += time - last;
    }
    cout << cost;
    return 0;
}