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

    vector<int> b_l(n + 1, 0), b_r(n + 1, 0);
    vector<int> pre(n + 1, 0);

    for (int i = 1; i <= n;) {
        if (s[i] == '1') {
            int j = i + 1;
            while (j <= n && s[j] == '1') j++;

            int r = j - 1;
            for (int k = i; k < j; k++) {
                b_l[k] = i;
                b_r[k] = r;
                pre[k] = 1;
            }

            i = j;
        } else i++;
    }

    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];

    while (q--) {
        int l, r; cin >> l >> r;
        int m = r - l + 1, k = m / 3;

        if (s[l] == '1' && b_r[l] >= r) {
            int mis = m / 2;
            cout << max(k - mis, 0) << (q ? "\n" : "");
            continue;
        }

        int c_l = 0, c_r = 0;
        int u = l, v = r;

        if (s[l] == '1') {
            c_l = b_r[l] - l + 1;
            u = b_r[l] + 1;
        }
        if (s[r] == '1') {
            c_r = r - b_l[r] + 1;
            v = b_l[r] - 1;
        }

        int mis = 0;

        if (u <= v) mis += (max(pre[v] - pre[u - 1], 0) + 1) / 2;

        if (c_l) mis += (c_l + 1) >> 1;
        if (c_r) mis += (c_r + 1) >> 1;

        if (c_l && c_r && c_l & 1 && c_r & 1) mis--;

        cout << max(k - mis, 0) << (q ? "\n" : "");
    }
    return 0;
}