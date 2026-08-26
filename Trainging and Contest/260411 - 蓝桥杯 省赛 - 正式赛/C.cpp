#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
	ios;
	ll n, m; cin >> n >> m;
	ll t = ((m - (m % 32)) + (m % 32 != 0 ? 32 : 0));
	cout << (t * n / 8);
	return 0;
}
