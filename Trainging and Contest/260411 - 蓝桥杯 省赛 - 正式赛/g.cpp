#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
ll solve() {
	int n, c;
	ll w;
	cin >> n >> c >> w;
	if (n == 1) {
		return c == w ? 1 : 0;
	}
	if (w % c != 0) return -1;
	vector<ll> a(n);
	ll cnt = LLONG_MAX;
	ll sum = 0;
	set<ll> sum_hash;
	for (int i = 1; i <= n; i++) {
		a[i - 1] = i * c;
		sum += a[i - 1];
		
		if (sum == w || a[i - 1] == w) {
			cnt = 1;
			break;
		}
		
		if (sum_hash.count(sum - w)) {
			cnt = 1;
			break;
		}
		sum_hash.insert(sum);
	}
	if (cnt == 1) return 1;
	
	ll sum_back = 0, scnt = 0, last_i = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (sum_back + a[i] > w) {
			continue;
		}
		if (last_i == -1 || last_i - 1 > i) scnt++;
		sum_back += a[i];
		last_i = i;
	}
	if (sum_back == w) cnt = min(scnt, cnt);
	
	return cnt == LLONG_MAX ? -1 : cnt;
}
int main() {
	ios;
	int t; cin >> t;
	while (t--) {
		cout << solve() << (t != 0 ? "\n" : "");
	}
	return 0;
}
