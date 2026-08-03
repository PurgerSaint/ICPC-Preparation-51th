#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

char solve() {
    int n; cin >> n;
    vector<pair<char, set<string>>> log(26);
    for (int i = 0; i < 26; i++)
        log[i].first = char('A' + i);
    for (int i = 0; i < n; i++) {
        string name, state;
        char c;
        cin >> name >> c >> state;
        if (state == "accepted") {
            log[c - 'A'].second.insert(name);
        }
    } 
    sort(range(log), [](auto& a, auto& b){
        if (a.second.size() == b.second.size()) return a.first < b.first;
        return a.second.size() > b.second.size();
    });
    return log[0].first;
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
