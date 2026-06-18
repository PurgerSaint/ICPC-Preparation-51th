#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);
using ll = long long;
int main() {
	ios;
	int n;
	cin >> n;
	int c = n % 2 == 1 ? (n / 2 + 1) : -1;
	double sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			double t = i * j * (i + j);
			if (i == j) t *= 2.0;
			if (i == 1 || i == n || j == 1 || j == n) t /= 2.0;
			if (i == c && j == c) t += 100;
			sum += t;
		}
	cout << sum;
	return 0;
}
