#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main(){
    IOS;
    int n, m; cin>>n>>m;
    // 警醒1：值不能设置为int，因为对应键只有唯一值
    unordered_map<int,unordered_set<int>> hash;
    for (int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        hash[a].insert(b);
    }
    for (int i = 1; i < n; i++) {
        if (hash.find(i) == hash.end() || hash[i].find(i+1) == hash[i].end()) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}