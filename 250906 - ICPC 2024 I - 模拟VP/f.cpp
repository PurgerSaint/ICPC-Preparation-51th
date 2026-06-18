#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int solve(){
    int n; cin>>n;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) cin>>a[i];
    a[0] = LLONG_MAX;
    a[n + 1] = LLONG_MAX;
    vector<int> l(n + 2), r(n + 2);
    vector<int> stk;

    stk.clear();
    stk.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[i] > a[stk.back()])
            stk.pop_back();
        l[i] = stk.back() + 1;
        if(a[l[i]] == a[i]) l[i] = i;
        stk.push_back(i);
    }

    stk.clear();
    stk.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[i] > a[stk.back()])
            stk.pop_back();
        r[i] = stk.back() - 1;
        if (a[r[i] + 1] == a[i]) r[i] = i;
        stk.push_back(i);
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += r[i] - l[i];
    }
    return sum;
}
int main(){
    IOS;
    int t; cin>>t;
    while(t--) {
        cout << solve() << (t == 0 ? "" : "\n");
    }
    return 0;
}
