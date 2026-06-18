#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int solve() {
    int n, m; cin>>m>>n;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        mp[a].push_back(b);
    }
    vector<pair<int, vector<int>>> adj(mp.begin(), mp.end());
    
    multiset<int> s;
    int res = n;
    for (int i = 0; i < adj.size(); i++) {
        const int& left = adj[i].first;
        vector<int>& right = adj[i].second;

        for (int& t : right) s.insert(t);
        int end = i + 1 == adj.size() ? n : adj[i + 1].first;
        for (int j = left; j < end; j++) {
            while (!s.empty() && *s.begin() <= j) {
                s.erase(s.begin());
            }
            if (s.empty()) break;
            res--;
            s.erase(s.begin());
        }
    }
    return res;
}
int main() {
    IOS;
    int t; cin>>t;
    while(t--) {
        cout<<solve()<<(t != 0 ? "\n" : "");
    }
    return 0;
}