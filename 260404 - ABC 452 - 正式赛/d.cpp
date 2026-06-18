#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

string s, t;
int cnt = 0;
int n, m;

void dfs(int i, int j, string path) {
    if (i == n || j == m) return;
    if (!path.empty() && j != m) {
        cnt++;
    }

    dfs(i + 1, (s[i + 1] == t[j] ? j + 1 : j), path + s[i + 1]);

}

int main() {
    ios;
    cin >> s >> t;
    n = s.length(), m = t.length();
    string path = "";
    for (int j = 0; j < n; j++)
        dfs(j, (s[j] == t[0] ? 1 : 0), path + s[j]);
    cout << cnt;
    return 0;
}