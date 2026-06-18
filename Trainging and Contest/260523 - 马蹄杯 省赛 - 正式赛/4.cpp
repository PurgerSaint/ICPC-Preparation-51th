#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll val = 0;
        for (int j = i; j < n; j++) {
            val += a[j];
            bitset<1000> b(val);
            cnt += b.count();
        }
    }
    cout << cnt;
    return 0;
}