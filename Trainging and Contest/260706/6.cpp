#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int tt; cin >> tt;
    map<char,char> mp;
    while (tt--) {
        int n; cin >> n;
        stack<char> a;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (!a.empty() && (c == ')' && a.top() == '(')) {
                cnt++;
                a.pop();
                continue;
            }
            a.push(c);
        }
        cout << (a.size() / 2) << (tt? "\n" : "");
    }
    return 0;
}