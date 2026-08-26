#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

vector<vector<int>> mp;
vector<ll> a;
int n;

int main() {
    int m; cin >> n >> m;
    a = vector<ll>(n);
    for (ll& t: a) cin >> t;
    mp = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for (vector<int>& p: mp)
        sort(p.begin(), p.end(), [&](int& x, int& y){
            return a[x - 1] < a[y - 1];
        });
    int q; cin >> q;
    while (q--) {
        int u; ll x; cin >> u >> x;
        set<int> st;
        queue<int> qe;
        qe.push(u);
        while (!qe.empty()) {
            int t = qe.front(); qe.pop();
            st.insert(t);
            for (int& k: mp[t]) {
                if (a[k - 1] > x ) break;
                if (!st.count(k)) qe.push(k); 
            }
        }
        cout << st.size() << (q != 0 ? "\n" : "");
    }
    return 0;
}