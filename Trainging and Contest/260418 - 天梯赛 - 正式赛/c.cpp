#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int a, b; cin >> a >> b;
    int t = b - a;
    cout << t << "\n";
    if (t <= 0) cout << "hai sheng ma?";
    else {
        if (t <= 250) cout << "nin tai cong ming le!";
        else cout << "jiu ting tu ran de...";
    }
    return 0;
}