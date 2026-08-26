#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    string res = "";
    while (true) {
        string s; cin >> s;
        bool f = 0;
        for (char c: s) {
            if (c == 'E') {
                f = 1;
                break;
            }
            if (c != 'L' && c != 'W') continue;
            res += c;
        }
        if (f) break;
    }
    vector<pair<int, int>> a, b;
    int n = res.length();
    a.push_back({0, 0});
    b.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        if (res[i] == 'W') {
            a.back().first++;
            b.back().first++;
        } else {
            a.back().second++;
            b.back().second++;
        }

        auto& [x1, y1] = a.back();
        if (max(x1, y1) >= 11 && abs(x1 - y1) >= 2) a.push_back({0, 0});
        auto& [x2, y2] = b.back();
        if (max(x2, y2) >= 21 && abs(x2 - y2) >= 2) b.push_back({0, 0});
    }
    for (auto& [x, y]: a)
        cout << x << ":" << y << "\n";
    cout << "\n";
    for (auto it = b.begin(); it != b.end(); it++) {
        auto& [x, y] = *it;
        cout << x << ":" << y;
        if (it + 1 != b.end()) cout << "\n";
    }
    return 0;
}