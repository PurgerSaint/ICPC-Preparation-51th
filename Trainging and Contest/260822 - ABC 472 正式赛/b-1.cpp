#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const int MOD = 20220911;
int dfs() {
    int cnt = 0;
    while (1) {
        string s; cin >> s;
        if (s == "library") cnt = mod(cnt + 1, MOD);
        if (s == "repeat") cnt = mod(cnt + dfs(), MOD);
        if (s == "for") {
            int g; cin >> g;
            return mod(g * cnt, MOD);
        }
        if (s == "fin") break;
    }
    return mod(cnt, MOD);
}

int main() {
    ios;
    cout << dfs();
    return 0;
}