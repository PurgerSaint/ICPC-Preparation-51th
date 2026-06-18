#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, k; cin >> n >> k;
    if ((n < 10 && k <= n)) {
        cout << 1;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0, t = i;
        while (t >= 1) {
            sum += (t % 10);
            t /= 10;
            if (sum > k) break;
        }
        if (sum == k) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}