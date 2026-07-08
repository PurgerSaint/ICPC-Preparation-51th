#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);

int main() {
    ios;
    int n; cin >> n;
    string s; cin >> s;
    
    deque<int> dq;
    bool rev = 0;

    for (int i = 1; i <= n; i++) {
        if (!rev) dq.push_back(i);
        else dq.push_front(i);
        if (s[i - 1] == 'o') rev = !rev;
    }

    if (rev)
        for (int i = n - 1; i >= 0; i--)
            cout << dq[i] << (i > 0 ? " " : "");
    else
        for (int i = 0; i < n; i++)
            cout << dq[i] << (i < n - 1 ? " " : "");
    return 0;
}