#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = 0;
            if (i > 0) t++;
            if (i < n - 1) t++;
            if (j > 0) t++;
            if (j < m - 1) t++;
            cout << t;
            if (j != m - 1) cout << " ";
        }
        if (i != n - 1) cout << "\n";
    }
    return 0;
}