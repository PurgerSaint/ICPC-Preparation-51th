#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
void resverse(string& t) {
    int x, y; cin >> x >> y;
    if (x == y) return;
    string a = "";
    for (int i = y; i >= x; i--)
        a += t[i];
    int sz = a.length();
    for (int i = 0; i < sz; i++)
        t[x + i] = a[i];
}

void insert(string& t) {
    int x; cin >> x;
    string s; cin >> s;
    if (x == 0) {
        t = s + t;
        return;
    }
    if (x == t.size()) {
        t = t + s;
        return;
    }
    string a = "";
    while (t.size() > x) {
        a += t.back();
        t.pop_back();
    }
    t += s;
    while (!a.empty()) {
        t += a.back();
        a.pop_back();
    }
}

void find(string& t) {
    string a; cin >> a;
    int sz = t.length(), asz = a.length();
    vector<int> loc;
    for (int i = 0; i < sz; i++) {
        if (t[i] == a.front()) {
            if (asz == 1) {
                loc.push_back(i);
                continue;
            }
            for (int j = 1; j < asz; j++) {
                if (t[i + j] != a[j]) break;
                if (j == asz - 1) loc.push_back(i); 
                if (loc.size() == 3) break;
            }
        }
    }
    if (loc.empty()) cout << "-1";
    else {
        int loc_sz = loc.size();
        for (int i = 0; i < loc_sz; i++)
            cout << loc[i] << (i != loc_sz - 1 ? " " : "");
    }
}

int main() {
    ios;
    int n; cin >> n;
    string t; cin >> t;
    while (n--) {
        int k; cin >> k;
        if (k == 1) find(t);
        else if (k == 3) {
            resverse(t);
            cout << t;
        } else if (k == 2) {
            insert(t);
            cout << t;
        }
        if (n != 0) cout << "\n";
    }
    return 0;
}