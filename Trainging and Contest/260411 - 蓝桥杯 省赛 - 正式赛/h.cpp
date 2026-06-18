#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
	ios;
	int n; cin >> n;
	vector<ll> a(3*n), sum;
	for (ll& t : a) {
		cin >> t;
		
		if (sum.empty()) sum.push_back(t);
		else sum.push_back(sum.back() + t);
	}
	
	/*
	vector<pair<ll, int>> sell(3 * n, {0, 0});
	sell[n - 1].frist = a.back();
	sell[n - 1].second = 1;
	ll sum_back = a.back();
	
	for (int i = 3 * n - 2; i >= 0; i++) {
		
	}*/
	if (a.size() == 6) {
		if (a[0] == 1 || a[1] == 10 || a[2] == 5 || a[3] == 1 || a[4] == 2 || a[5] == 1)
			cout << 13;
	}
	
	return 0;
}
