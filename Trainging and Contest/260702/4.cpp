#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

bool dfs(int d, int& n) {
    if (d > n) return false;
    if (n % d == 0) return true;
    return dfs(d * 10 + 4, n) || dfs(d * 10 + 7, n);
}

int main() {
    ios;
    int n; cin >> n;
    if (dfs(4, n) || dfs(7, n)) cout << "YES";
    else cout << "NO";
    return 0;
}