#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n; cin >> n;
    vector<vector<ll>> pay(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> pay[i][j];

    bool flag = false;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {

            for (int k = j; k <= n; k++) {
                if (pay[i][j] + pay[j][k] < pay[i][k]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}