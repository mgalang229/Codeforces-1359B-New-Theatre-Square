#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	y = min(y, 2 * x);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '*') {
				continue;
			}
			int index = j;
			// count the no. of consecutive dots
			while (index + 1 < m && s[index+1] == '.') { 
				index++;
			}
			int length = index - j + 1; // length of the consecutive dots
			// (length % 2) * x = cost of cells using x burles (1 x 1)
			// (length / 2) * y = cost of pairs of cells using 1 y burle (1 x 2) or 2 x burles (1 x 1)
			ans += ((length % 2) * x + (length / 2) * y);
			j = index + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

