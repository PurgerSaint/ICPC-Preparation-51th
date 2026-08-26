#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n - 1);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;
    vector<int> x(n - 1, 0);
    for (int i = 1; i < n; i++)
        x[i] = (b[i - 1] - x[i - 1] + m) % m;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] != x[i];
    cout << min(sum, n - sum);
    return 0;
}