#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    vector<vector<bool>> able(n + 1, vector<bool>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        set<int> st;
        for (int j = i; j < n; j++) {
            if (st.count(a[j])) break;
            st.insert(a[j]);
            if (*(st.rbegin()) - *(st.begin()) == j - i)
                able[*(st.begin())][*(st.rbegin())] = 1;
        }
    }
    for (int w = n; w > 0; w--) {
        for (int i = 1; i + 2 * w - 1 <= n; i++) {
            if (able[i][i + w - 1] && able[i + w][i + 2 * w - 1])
                return w;
        }
    }
    return 0;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}
