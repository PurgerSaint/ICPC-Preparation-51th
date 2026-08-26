#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
    ios;
    char s[10];
    scanf("%s", s);
    printf("%s", (strlen(s) % 5 == 0 ? "Yes" : "No"));
    return 0;
}