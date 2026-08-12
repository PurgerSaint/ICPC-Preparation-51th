#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    vector<int> h(n);
    for (int& t: h) cin >> t;
    vector<int> up(n, 1), low(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (h[j] < h[i])
                up[i] = max(up[i], 1 + up[j]);
    }
    for (int j = n - 1; j >= 0; j--) {
        for (int i = j + 1; i < n; i++)
            if (h[j] > h[i])
                low[j] = max(low[j], low[i] + 1);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        int l = max(0, i + 1 - up[i]), r = max(0, n - i - low[i]);
        // if (!l || !r) continue;
        ans = min(l + r, ans);
    }
    cout << ans;
    return 0;
}
