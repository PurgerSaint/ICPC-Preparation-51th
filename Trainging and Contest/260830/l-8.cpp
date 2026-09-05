#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    string s; cin >> s;
    int k; cin >> k;
    int n = s.length();
    string a = "";
    for (char c: s) {
        while (!a.empty() && k && a.back() > c) {
            k--;
            a.pop_back();
        }
        a += c;
    }
    while (!a.empty() && k) {
        k--;
        a.pop_back();
    }
    int start = 0;
    while (start < a.size() && a[start] == '0') start++;
    string ans = a.substr(start);
    if (ans == "") cout << 0;
    else cout << ans;
    return 0;
}