#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) (t % m + m) % m
#define range(a) a.begin(),a.end()

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
        s[i] == 'a' ? a.push_back(i) : b.push_back(i);
    if (a.empty() || b.empty()) return 0;
    if (a.back() - a[0] + 1 == (int)a.size() ||  b.back() - b[0] + 1 == (int)b.size()) return 0;

    int m_1 = (int)a.size();
    vector<int> a1(m_1);
    for (int i = 0; i < m_1; i++)
        a1[i] = abs(a[i] - i);
    ll ans_a = 0;
    int mid_a = a1[m_1 / 2];
    for (int i = 0; i < m_1; i++)
        ans_a += abs(a1[i] - mid_a);

    int m_2 = (int)b.size();
    vector<int> b1(m_2);
    for (int i = 0; i < m_2; i++)
        b1[i] = abs(b[i] - i);
    ll ans_b = 0;
    int mid_b = b1[m_2 / 2];
    for (int i = 0; i < m_2; i++)
        ans_b += abs(b1[i] - mid_b);

    return min(ans_a, ans_b);
}

int main() {
    ios;
    int tt; cin >> tt;
    while (tt--) {
        cout << solve();
        cout << (tt ? "\n" : "");
    }
    return 0;
}
