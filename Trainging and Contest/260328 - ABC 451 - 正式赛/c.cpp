#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    set<ll> tree;
    unordered_map<ll, int> hash;
    int q; cin >> q;
    int sum = 0;
    while (q--) {
        int c; ll h; cin >> c >> h;
        if (c == 1) {
            if (!tree.count(h))
                tree.insert(h);
            hash[h]++;
            sum++;
        } else {
            auto it = tree.upper_bound(h);
            for (auto i = tree.begin(); i != it; i++) {
                if (sum >= hash[*i])
                    sum -= hash[*i];
                hash[*i]=0;
            }
        }
        cout << sum;
        if (q != 0) cout << "\n";
    }
    return 0;
}