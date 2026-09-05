#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    sort(range(a));
    deque<int> dq;
    for (int& t: a) dq.push_back(t);
    ll sum = 0, last = 0;
    bool f = 0;
    while (!dq.empty()) {
        int now = 0;
        if (f) {
            now = dq.front();
            dq.pop_front();
        } else {
            now = dq.back();
            dq.pop_back();
        }
        sum += (ll)(now - last) * (now - last);
        last = now;
        f = !f;
    }
    cout << sum;
    return 0;
}