#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

map<string, vector<string>> mp;

string solve() {
    int n, j, k; cin >> n >> j >> k;
    string p = to_string(n);
    if (j == k) return to_string((int)p.length()) + "A0B";
    int a = 0;
    vector<string>& g = mp[p];
    string& s = g[j - 1], t = g[k - 1];
    for (int i = 0; i < (int)p.length(); i++)
        if (s[i] == t[i]) a++;
    return to_string(a) + "A" + to_string((int)p.length() - a) + "B";
}

int main() {
    ios;
    mp["12"] = {"12", "21"};
    mp["123"] = {"123", "132", "213", "231", "312", "321"};
    mp["1234"] = {
        "1234", "1243",
        "1324", "1342",
        "1423", "1432",
        "2134", "2143",
        "2314", "2341",
        "2413", "2431",
        "3124", "3142",
        "3214", "3241",
        "3412", "3421",
        "4123", "4132",
        "4213", "4231",
        "4312", "4321"
    };
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}