#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int main() {
    IOS;
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            int a; cin>>a;
            m = min(m, a);
        }
        cout << m << "\n";
    }
    return 0;
}