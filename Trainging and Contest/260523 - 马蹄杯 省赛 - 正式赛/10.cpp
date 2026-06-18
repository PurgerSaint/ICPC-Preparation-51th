#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
bool check(int a, int b, int c) {
    return (a + b) > c && (a + c) > b && (b + c) > a;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& t: a) cin >> t;
    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (check(a[i], a[j], a[k]))
                    cnt++;
    cout << cnt;
    return 0;
}