#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, k; cin >> n >> k;
    vector<int> cnt(k + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cnt[t]++;
    }
    sort(range(cnt));
    cout << (cnt.end() - lower_bound(cnt.begin() + 1, cnt.end(), cnt.back() - 1));
    return 0;
}