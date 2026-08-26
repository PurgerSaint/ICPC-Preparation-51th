#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<string> rank1, rank2, rank;
    set<string> rk1, rk2, rk;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (!rk1.count(s)) {
            rk1.insert(s);
            rank1.push_back(s);
        }
    }
    for (int i = 1; i <= m; i++) {
        string s; cin >> s;
        if (!rk2.count(s)) {
            rk2.insert(s);
            rank2.push_back(s);
        }
    }
    int sz_a = rank1.size(), sz_b = rank2.size();
    for (int i = 0; i < min(sz_a, sz_b); i++) {
        string& a = rank1[i], b = rank2[i];
        if (!rk.count(a)) {
            rank.push_back(a);
            rk.insert(a);
        }
        if (!rk.count(b)) {
            rank.push_back(b);
            rk.insert(b);
        }
    }
    if (sz_a > sz_b) {
        for (int i = sz_b; i < sz_a; i++)
            if (!rk.count(rank1[i])) {
                rank.push_back(rank1[i]);
                rk.insert(rank1[i]);
            }
    } else if (sz_a < sz_b) {
        for (int i = sz_a; i < sz_b; i++)
            if (!rk.count(rank2[i])) {
                rank.push_back(rank2[i]);
                rk.insert(rank2[i]);
            }
    }
    for (auto it = rank.begin(); it != rank.end(); it++)
        cout << *it << (it + 1 != rank.end() ? "\n" : "");
    return 0;
}
