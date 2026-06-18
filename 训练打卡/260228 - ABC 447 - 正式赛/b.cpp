#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    string s; cin >> s;
    unordered_map<int, unordered_set<char>> hash;
    vector<pair<char, int>> a;
    for (int i = 0; i < 26; i++) a.push_back({'a' + i, 0});
    for (char c: s) a[c - 'a'].second++;
    sort(a.begin(), a.end(), [](pair<char, int>& x, pair<char, int>& y){
        return x.second > y.second;
    });
    int mx = 0;
    for (pair<char, int>& p: a) {
        hash[p.second].insert(p.first);
        mx = max(mx, p.second);
    }
    for (char c: s) {
        if (hash[mx].count(c)) continue;
        cout << c;
    }
    return 0;
}