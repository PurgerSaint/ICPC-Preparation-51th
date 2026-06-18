#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int solve() {
    int s; cin>>s;
    vector<int> a(7);
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    return max(a[0], max(a[1], a[3]));
}
int main() {
    IOS;
    int t; cin>>t;
    while(t--) {
        cout << solve() << (t != 0 ? "\n" : "");
    }
    return 0;
}