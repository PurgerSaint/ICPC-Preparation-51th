#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    string s; cin >> s;
    string target = "hello";
    int cnt = 0;
    bool flag = 0;
    for (char c: s) {
        if (c == target[cnt]) {
            cnt++;
        }
        if (cnt == target.size()) {
            flag = 1;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}