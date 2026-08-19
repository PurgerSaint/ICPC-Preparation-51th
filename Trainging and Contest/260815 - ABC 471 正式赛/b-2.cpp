#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, m; cin >> n >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        st.insert({l, r});
    }
    for (int i = 1; i < n; i++) {
        if (!st.count({i, i + 1})) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}