#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

ll key(int l, int r) {
    return (1LL * l << 32) ^ (unsigned int)r;
}

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    unordered_map<int, vector<int>> start;
    unordered_map<int, vector<int>> finish;
    unordered_map<ll, int> cnt;

    for (pair<int, int>& p: a) {
        cin >> p.first >> p.second;

        start[p.first].push_back(p.second);
        finish[p.second].push_back(p.first);
        cnt[key(p.first, p.second)]++;
    }

    for (auto& p: start)
        sort(p.second.begin(), p.second.end());
    for (auto& p: finish)
        sort(p.second.begin(), p.second.end());

    int q; cin >> q;
    while (q--) {
        
    }
    return 0;
}