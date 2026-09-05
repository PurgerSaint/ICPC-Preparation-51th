#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(0);cin.tie(0);
#define range(a) a.begin(), a.end()
#define mod(t, m) ((t) % m + m) % m

int main() {
    ios;
    int n, b; cin >> n >> b;
    vector<string> a(n);
    unordered_set<string> st;
    for (string& s: a) {
        cin >> s;
        st.insert(s);
    }
    vector<int> diff(b, 0);
    int cnt = 0;
    for (string& s: a) {
        char c = ' ';
        for (int i = 0; i < b; i++) {
            c = s[i];
            s[i] = c == '1' ? '0' : '1';
            if (st.count(s)) {
                diff[i]++;
                cnt++;
            }
            s[i] = c;
        }
    }
    cout << cnt / 2 << "\n";
    for (int i = 0; i < b; i++)
        cout << diff[i] / 2 << (i < b - 1 ? " " : "");
    return 0;
}