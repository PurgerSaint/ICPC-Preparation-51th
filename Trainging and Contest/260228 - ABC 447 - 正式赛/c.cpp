#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    string s, t; cin >> s >> t;
    if (s == t) {
        cout << 0;
        return 0;
    }

    string ss = "", ts = "";
    vector<int> as, ta;
    
    int cnta = 0;
    for (char c: s) {
        if (c != 'A') {
            ss += c;
            as.push_back(cnta);
            cnta = 0;
        } else cnta++;
    }
    as.push_back(cnta);

    cnta = 0;
    for (char c: t) {
        if (c != 'A') {
            ts += c;
            ta.push_back(cnta);
            cnta = 0;
        } else cnta++;
    }
    ta.push_back(cnta);

    if (ss != ts) {
        cout << -1;
        return 0;
    }

    ll cnt = 0;
    int size = ta.size();
    for (int i = 0; i < size; i++)
        cnt += abs(ta[i] - as[i]);

    cout << cnt;
    return 0;
}


