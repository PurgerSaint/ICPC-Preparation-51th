#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

const int MOD = 20220911;
vector<string> t;
int dfs() {
    int cnt = 0;
    while (true) {
        string s; cin >> s;
        // cout << s << "\n";
        if (s == "fin") break;
        if (s == "repeat") {
            cnt = mod(cnt + dfs(), MOD);
            continue;
        }
        if (s == "for") {
            int g; cin >> g;
            return mod(cnt * g, MOD);
        }
        if (s == "library") cnt++;
        t.push_back(s);
    }
    return cnt;
}

int main() {
    ios;
    cout << mod(dfs(), MOD);
    return 0;
}

/*
repeat
    library
    repeat
        arithmetic
        library
    for 3 times
    repeat
        library
    for 2 times
    arithmetic
for 4 times arithmetic
fin

repeat
    library
    repeat
        repeat
            library
        for 3 times
        arithmetic
        library
    for 3 times
for 100 times fin
*/