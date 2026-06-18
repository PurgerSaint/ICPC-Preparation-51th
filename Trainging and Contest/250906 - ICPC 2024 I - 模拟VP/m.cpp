#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int solve(){
    int a, b; cin>>a>>b;
    if (a == b) return 0;
    if (a % b == 0 || b % a == 0) return 1;
    return 2;
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        cout << solve() << (t == 0 ? "" : "\n");
    }
    return 0;
}