#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

vector<vector<int>> ans;
int rank_p = -1, rank_q = -1;
vector<int> p, q;
int n;
void dfs(vector<int> path, string s) {
    if ((int)path.size() == n) {
        if (path == p) rank_p = ans.size();
        else if (path == q) rank_q = ans.size();
        ans.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') continue;
        s[i - 1] = '1';
        path.push_back(i);
        dfs(path, s);
        s[i - 1] = '0';
        path.pop_back();
    }
}

int main() {
    ios;
    cin >> n;
    p = vector<int>(n);
    q = vector<int>(n);
    for (int& t: p) cin >> t;
    for (int& t: q) cin >> t;
    string s(10, '0');
    for (int i = 1; i <= n; i++) {
        s[i - 1] = '1';
        dfs({i}, s);
        s[i - 1] = '0';
    }
    cout << max(0, rank_q - rank_p - 1);
    return 0;
}
