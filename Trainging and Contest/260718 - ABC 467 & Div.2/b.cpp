#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int a, b; string s; cin >> a >> b >> s;
        if (a == b || s == "take") continue;
        ans += b - a;
    }
    cout << ans;
    return 0;
}