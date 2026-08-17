#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m
const ll INF = 1LL << 60;

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t > 0) a.push_back(t);
        else b.push_back(t);
    }
    sort(range(a), greater<ll>());
    sort(range(b));
    // cout << a.back() << " " << b.back() << "\n";
    ll sum = 0;

    sum += a.front() - a.back();
    sum += abs(b.front() - b.back());
    if (a.back() >= abs(b.back())) {
        sum += abs(b.back()) + a.back() - b.front();
    } else {
        sum += a.back() + a.front() - b.back();
    }
    cout << sum;
    return 0;
}