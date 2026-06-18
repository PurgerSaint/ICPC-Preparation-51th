#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<vector<int>> wp(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int w; cin >> w;
            wp[i].push_back(j);
        }
    vector<vector<int>> wp(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            
        }
    return 0;
}