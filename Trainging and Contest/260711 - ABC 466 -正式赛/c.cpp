#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m

bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string rep; cin >> rep;
    if (rep != "Yes" && rep != "No") exit(0);
    return rep == "Yes";
}

int main() {
    ios;
    int n; cin >> n;
    int cnt = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        if (r < i) r = i;
        while (r + 1 <= n && ask(i, r + 1)) r++;
        cnt += r - i;
    }
    cout << "! " << cnt << endl;
    return 0;
}