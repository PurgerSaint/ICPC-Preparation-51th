#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()


int main() {
    ios;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << "Fizz";
        else cout << i;
        if (i < n) cout << "\n";
    }
    return 0;
}
