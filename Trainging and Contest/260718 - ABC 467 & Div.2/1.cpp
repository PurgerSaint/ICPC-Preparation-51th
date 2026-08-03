#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

bool solve() {
    int n; cin >> n;
    int s = 0;
    vector<pair<int, int>> cnt;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        s += t;
        if (cnt.empty() || cnt.back().first != t) cnt.push_back({t, 1});
        else cnt.back().second++;
    }
    if (s == 0) return true;
    if (n % 2 || abs(s) % 2 || (n == 2 && s != 0)) return false;
    int a = 0, b = 0;
    for (auto& [t, time]: cnt) {
        if (time < 2) continue;
        int& c = t == 1 ? a : b;
        c += time / 2;
    }
    int g = (abs(s) / 2);
    return !(g % 2) && ((s > 0 && g <= a) || (s < 0 && g <= b));
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO");
        if (tt) cout << "\n";
    }
    return 0;
}