#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& t: a) cin >> t;
    sort(a.begin(), a.end());
    
    auto check = [&](ll L) -> bool {
        multiset<ll> t(a.begin(), a.end());
        while (!t.empty()) {
            ll cur = *t.rbegin();
            t.erase(prev(t.end()));
            if (cur == L) continue;

            ll target = L - cur;
            auto it = t.find(target);
            if (it == t.end()) return false;
            t.erase(it);
        }
        return true;
    };

    set<ll> res;
    if (check(a.back())) res.insert(a.back());
    if (n > 1 && check(a[n-1] + a[0])) res.insert(a[n-1] + a[0]);
    int size = res.size(), cnt = 0;
    for (const ll& t: res)
        cout << t << ((++cnt) != size? " " : "");
    return 0;
}