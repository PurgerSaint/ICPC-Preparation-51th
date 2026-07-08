#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> h(n);
        for (int& t: h) cin >> t;

        for (int s = 0; s < n; s++) {
            vector<int> w(n, 0), w1(n, 0), w2(n, 0);
            for (int i = 1; i < n; i++)
                w1[mod(s + i, n)] = max(w1[mod(s + i - 1, n)], h[mod(s + i - 1, n)]);
            for (int i = 1; i < n; i++)
                w2[mod(s - i, n)] = max(w2[mod(s - i + 1, n)], h[mod(s - i, n)]);
            for (int i = 0; i < n; i++)
                w[i] = min(w1[i], w2[i]);
            cout << accumulate(w.begin(), w.end(), 0ll);
            if (s < n - 1) cout << " ";
            else if (tt) cout << "\n";
        }
    }
    return 0;
}