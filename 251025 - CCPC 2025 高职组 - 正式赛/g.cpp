#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
int main() {
    IOS;
    int n, k; cin >> n >> k;
    vector<int> a;
    vector<bool> prime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int p = 2; i * p <= n; p++)
                prime[i*p] = false;
        }
    }
    for (int i = 1; i <= n; i++)
        if (prime[i])
            a.push_back(i);
    if (a.size() >= k) {
        cout << "YES\n";
        for (int i = 0; i < k; i++)
            cout << a[i] << (i != k-1 ? " " : "");
    } else cout << "NO";
    return 0;
}