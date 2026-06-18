#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;

int main() {
    ios;
    string s; cin >> s;
    int n = s.length();
    int a[10] = {0};
    for (char c: s) {
        int i = c - '0';
        a[i]++;
        if (a[i] == n) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}