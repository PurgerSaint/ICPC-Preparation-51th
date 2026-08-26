#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

int main() {
    ios;
    int n; cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (cnt.count(s))
            cout << (s + to_string(cnt[s]));
        else
            cout << "OK";
        cnt[s]++;
        if (i < n - 1) cout << "\n";
    }
    return 0;
}