#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    set<int> st;
    int ans = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            int val = a[x];
            ans ^= val ^ (val + 1);
            a[x]++;
            if (val == 0) st.insert(x);
        } else {
            for (auto it = st.begin(); it != st.end();) {
                int i = *it, val = a[i];
                ans ^= val ^ (val - 1);
                a[i]--;
                if (a[i] == 0) it = st.erase(it);
                else it++;
            }
        }
        cout << ans << (q ? "\n" : "");
    }
    return 0;
}
