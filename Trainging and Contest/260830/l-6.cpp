#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a;
    a.push_back(0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (a.back() < t)
            sum += t - a.back();
        a.push_back(t);
    }
    cout << sum;
    return 0;
}