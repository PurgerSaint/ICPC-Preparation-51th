#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
using mat = vector<vector<ll>>;

int n, k;
const ll INF = 4e18;

mat multiply(const mat& A, const mat& B) {
    mat C(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < n; p++) {
            if (A[i][p] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (B[p][j] == INF) continue;
                C[i][j] = min(C[i][j], A[i][p] + B[p][j]);
            }
        }
    }
    return C;
}

mat power(mat A, ll exp) {
    mat res(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) res[i][i] = 0;

    while (exp > 0) {
        if (exp % 2 == 1) res = multiply(res, A);
        A = multiply(A, A);
        exp /= 2;
    }
    return res;
}

int main() {
    ios;
    cin >> n >> k;
    vector<vector<ll>> mp(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];
    
    mat res = power(mp, k);

    for (int i = 0; i < n; i++)
        cout << res[i][i] << (i != n - 1 ? "\n" : "");

    return 0;
}