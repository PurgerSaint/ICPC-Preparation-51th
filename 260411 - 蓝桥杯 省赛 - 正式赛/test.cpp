#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
	ios;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = 'A' + (s[i] - 'a');
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'a' + (s[i] - 'A');
	}
	cout << s;
	return 0;
}