#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[t]++;
    }
    int sum = 0;
    for (auto& [num, ct]: cnt) {
        if (ct % 2 == 0) continue;
        sum += num;
    }
    cout << sum;
    return 0;
}