#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    string s; cin >> s;
    vector<int> loc;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x')
            loc.push_back(i);
    }
    int hit = 0;
    for (int k = 1; k <= n; k++) {
        if (s[k - 1] == 'o') hit++;
        int ans;
        if (hit == 0) ans = k;
        else if (k > (int)loc.size()) ans = n;
        else ans = loc[k - 1] + 1;
        cout << ans << (k < n ? "\n" : "");
    }

    return 0;
}