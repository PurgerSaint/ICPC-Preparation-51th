#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int t, m;
vector<pair<int, int>> b;
vector<vector<int>> memory;
int dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= t) return 0;
    if (memory[i][j] != -1) return memory[i][j];
    int ans = dfs(i + 1, j);
    auto& [time, cost] = b[i];
    if (j + time <= t)
        ans = max(ans, cost + dfs(i + 1, j + time));
    return memory[i][j] = ans;
}

int main() {
    ios;
    cin >> t >> m;
    b = vector<pair<int, int>>(m);
    memory = vector<vector<int>>(m, vector<int>(t, -1));
    for (auto& [time, cost]: b)
        cin >> time >> cost;
    cout << dfs(0, 0);
    return 0;
}