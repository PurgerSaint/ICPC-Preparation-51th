#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
	ios;
	string s; cin >> s;
	int j = 0, cnt = 0;
	for (char c : s) {
		if (c == '2') {
			j++;
			if (j == 6) {
				cnt++;
				j = 0;
			}	
		} else if (c == '0' && (j == 1 || j == 4)) j++;
		else {
			if (c == '6' && j == 3) cnt++;
			j = 0;
		}
	}
	cout << cnt;
	return 0;
}
