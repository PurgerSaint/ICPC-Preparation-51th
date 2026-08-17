#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& t: a) cin >> t;
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        pos[t] = i;
    }
    vector<int> tail;
    for (int& t: a) {
        int loc = pos[t];
        auto it = lower_bound(range(tail), loc);
        if (it == tail.end()) tail.push_back(loc);
        else *it = loc;
    }
    cout << tail.size();
    return 0;
}