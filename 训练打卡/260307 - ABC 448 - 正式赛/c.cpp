#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, q; cin >> n >> q;
    vector<pair<int, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].first = i + 1;
    }
    sort(a.begin(), a.end(), [](pair<int, ll>& x, pair<int, ll>& y){
        return x.second < y.second;
    });
    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        set<int> index;
        while (k--) {
            int dx; cin >> dx;
            index.insert(dx);
        }
        ll nx = LLONG_MAX;
        for (int j = 0; j < n; j++) {
            if (!index.count(a[j].first)) {
                cout << a[j].second << (i != q - 1 ? "\n" : "");
                break;
            }
        } 
    }
    return 0;
}