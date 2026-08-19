#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = ' ' + s;

    vector<int> bl(n + 1, 0), br(n + 1, 0), pre(n + 1, 0);

    for (int i = 1; i <= n; ) {
        if (s[i] == '1') {
            int j = i + 1;
            while (j <= n && s[j] == '1') j++;
            
            int r = j - 1;
            for (int k = i; k < j; k++) {
                bl[k] = i;
                br[k] = r;
            }

            pre[i] = (j - i + 1) >> 1;
            i = j;
        } else i++;
    }

    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];

    while (q--) {
        int l, r; cin >> l >> r;
        int m = r - l + 1, k = m / 3;

        if (s[l] == '1' && br[l] >= r) {
            int mis = m >> 1;
            cout << max(0, k - mis) << (q ? "\n" : "");
            continue;
        }

        int c_l = 0, c_r = 0;
        int u = l, v = r;

        if (s[l] == '1') {
            c_l = br[l] - l + 1;
            u = br[l] + 1;
        }
        if (s[r] == '1') {
            c_r = r - bl[r] + 1;
            v = bl[r] - 1;
        }

        int mis = 0;

        if (u <= v) mis += pre[v] - pre[u - 1];

        if (c_l) mis += (c_l + 1) >> 1;
        if (c_r) mis += (c_r + 1) >> 1;

        if (c_l && c_r && c_l & 1 && c_r & 1)
            mis--;
        
        cout << max(0, k - mis) << (q ? "\n" : "");
    }
    return 0;
}