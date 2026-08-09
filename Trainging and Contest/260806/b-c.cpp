#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    string s; cin >> s;
    vector<int> x;
    for (int i = 0; i < n; i++)
        if (s[i] == 'x')
            x.push_back(i);
    vector<int> ans(n + 1, 0);
    int hit = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
        if (s[i - 1] == 'o') hit++;
        if (hit > (int)x.size()) ans[i] = n;
        else ans[i] = x[hit - 1] + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << (i < n ? "\n" : "");
    return 0;
}
