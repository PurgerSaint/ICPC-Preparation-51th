#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    string st = "";
    st += s.front();
    for (int i = 1; i < n; i++) {
        if (st.back() != s[i])
            st += s[i];
    }
    if (st.size() == 2) return 2;
    else return 1;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--)
        cout << solve() << (t ? "\n" : "");
    return 0;
}