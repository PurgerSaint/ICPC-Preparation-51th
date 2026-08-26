#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
#define between(a, b, t) (a <= t && t <= b)

int main() {
    ios;
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cout << i << (i < k ? " " : "");
    return 0;
}