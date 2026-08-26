#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, d; cin >> n >> d;
    string s; cin >> s;
    vector<int> g;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G')
            g.push_back(i);
    }
    if (g.empty()) {
        cout << n;
        return 0;
    }
    int last = -1, ans = 0;
    for (int& t: g) {
        int l = last == -1 ? -1 : (last + d);
        int r = t - d;
        if (r > l + 1) {
            ans += r - l - 1; 
            // cout << "ans:"  << ans << "\n";
        }
        last = t;
        // cout << l << " " << r << " " << t << "\n";
    }
    if (g.back() + d < n - 1) ans += (n - 1) - g.back() - d;
    cout << ans;
    return 0;
}
