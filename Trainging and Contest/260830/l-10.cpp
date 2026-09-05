#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n; cin >> n;
    vector<string> a(n);
    for (string& s: a) cin >> s;
    sort(range(a), [](string& x, string& y){
        return (x + y) > (y + x);
    });
    for (string& s: a) cout << s;
    return 0;
}