#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t,m) ((t) % m + m) % m

int main() {
    ios;
    multiset<ll> tree;
    int q; cin >> q;
    while (q--) {
        int c; ll h; cin >> c >> h;
        if (c == 1) tree.insert(h);
        else {
            while (!tree.empty() && *tree.begin() <= h)
                tree.erase(tree.begin());
        }
        cout << tree.size() << (q ? "\n" : "");
    }
    return 0;
}