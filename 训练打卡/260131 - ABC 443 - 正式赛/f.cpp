#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

struct State {
    int mod;    // 余数
    int last;   // 最后一位余数
    string num; // 数字字符串
};

string solve(int n) {
    vector<vector<bool>> vis(n, vector<bool>(10, false));
    
    queue<State> q;
    for (int i = 1; i <= 9; i++) {
        int mod = i % n;
        string num = to_string(i);
        if (mod == 0) return num;
        if (!vis[mod][i]) {
            vis[mod][i] = true;
            q.push({mod, i, num});
        }
    }

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        for (int i = cur.last; i <= 9; i++) {
            int mod = (cur.mod * 10 + i) % n;
            string num = cur.num + to_string(i);
            if (mod == 0) return num;

            if (!vis[mod][i]) {
                vis[mod][i] = true;
                q.push({mod, i, num});
            }
        }
    }

    return "-1";
}

int main() {
    ios;
    ll n; cin >> n;
    cout << solve(n);
    return 0;
}