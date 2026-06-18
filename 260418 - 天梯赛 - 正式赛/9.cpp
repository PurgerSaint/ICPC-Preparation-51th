#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n;
    double t;
    cin >> n >> t;
    deque<pair<int, int>> work;
    vector<int> loc;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val <= t) loc.push_back(i + 1);
        else {
            sum += val;
            work.push_back({val, i + 1});
        }
    }
    
    auto print = [&]() -> void {
        int sz = loc.size();
        for (int i = 0; i < sz; i++)
            cout << loc[i] << (i != sz - 1 ? " " : "");
    };
    if (loc.size() == n) print();

    int j = 0;
    int sz = work.size();
    t = sum / (double)sz;
    while (!work.empty()) {
        pair<int, int> p = work.back();
        work.pop_back();
        j++;
        if (p.first <= t) {
            loc.push_back(p.second);
            sum -= p.first;
        } else work.push_front(p);
        if (j == sz) {
            sz = work.size();
            t = sum / (double)sz;
            j = 0;
        }
    }
    print();
    return 0;
}