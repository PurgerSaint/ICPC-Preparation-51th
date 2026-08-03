#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()
#define lower(c) (c >= 'a' && c <= 'z')
#define upper(c) (c >= 'A' && c <= 'Z')
#define to_low(c) ('a' + (c - 'A'))
#define to_up(c) ('A' + (c - 'a'))

int main() {
    ios;
    string s; cin >> s;
    vector<int> a, b;
    for (int i = 0; i < (int)s.length(); i++)
        lower(s[i]) ? a.push_back(i) : b.push_back(i);
    if (a.size() >= b.size())
        for (int& i: b) s[i] = to_low(s[i]);
    else
        for (int& i: a) s[i] = to_up(s[i]);
    cout << s;
    return 0;
}