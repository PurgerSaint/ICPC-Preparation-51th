#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
unordered_map<ll, set<ll>> mp;
vector<bool> flag;
void expand(ll val) {
	for (ll i = flag.size(); i <= val; i++)
		flag.push_back(true);
	for (int i = 2; i <= val; i++) {
		if (flag[i]) {
			for (int j = 2; (i * j) <= val; j++) {
				if (!flag[i * j]) continue;
				flag[(i * j)] = false;
				mp[i * j].insert(i);
				mp[i * j].insert(j);
			}
		}
	}
}

string solve() {
	int m; cin >> m;
	ll t = 0, bad = 0;
	for (int i = 0; i < m; i++) {
		ll val; cin >> val;
		if (val != 1) {
			if (t != 0 && val != t) bad = 1;
			else t = val;
		}
	}
	if (bad || t == 0) return "NO";
	if (t + 1 >= flag.size()) expand(t);
	flag[0] = false;
	flag[1] = false;
	if (flag[t]) return "YES";
	else {
		while (!flag[t] && mp.count(t)) {
			t = mp[t].size() + 2;
		}
	}
	
	return flag[t] ? "YES" : "NO";
}
int main() {
	ios;
	int t; cin >> t;
	while (t--) {
		cout << solve() << (t != 0 ? "\n" : "");
	}
	return 0;
}
