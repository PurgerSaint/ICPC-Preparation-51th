#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100]={0}, b[100]={0};
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x - 1]++;
        b[y - 1]++;
    }
    for (int i = 0; i < m; i++)
        printf("%d%s", b[i]-a[i], (i != m - 1 ? "\n" : ""));
    return 0;
}