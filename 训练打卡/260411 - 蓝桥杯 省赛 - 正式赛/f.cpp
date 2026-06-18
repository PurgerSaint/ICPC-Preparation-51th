#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
string solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (ll& t: a) cin >> t;
	ll cnt = 0;
	while (!a.empty()) {
		if (a.back() > 1) {
			if (cnt % 2 == 0) {
				// cout << "L";
				if (a.size() > 1 && a.size() % 2 == 0) {
					a.back() -= 1;
					// cout << " step:1";
				} else {
					a.pop_back();
					// cout << " step:2";
				}
			} else {
				// cout << "Q";
				if (a.size() > 1 && a.size() % 2 != 0) {
					a.back() -= 1;
					// cout << " step:1";
				} else {
					a.pop_back();
					// cout << " step:2";
				}
			}
			// cout << " " << a.size() << "\n";
		} else {
			a.pop_back();
			// cout << (cnt % 2 == 0 ? "L" : "Q") << " end " << a.size() << "\n";
		}
		cnt++;
	}
	return cnt % 2 == 0 ? "Q" : "L";
}
int main() {
	ios;
	int t; cin >> t;
	while (t--) {
		cout << solve() << (t != 0 ? "\n" : "");
	}
	return 0;
}
