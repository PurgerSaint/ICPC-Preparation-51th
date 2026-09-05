#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    int suf = 1, pre = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) pre++;
        else break;
    }
    for (int i = n - 1; i > 1; i--) {
        if (a[i] > a[i + 1]) suf++;
        else break;
    }
    if (suf % 2 == 0 && pre % 2 == 0) cout << "Bob";
    else cout << "Alice";
    return 0;
}