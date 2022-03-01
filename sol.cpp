#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') { // check every row
				int index = j;
				int cost = 0;
				// perform a decision whether we should pave this cell using x burles
				// or choose two adjacent cells (current and previous) instead and pay y burles
				while (a[i][index] == '.' && index < m) {
					index++;
					if ((index - j) % 2 == 0) {
						cost = min(cost + x, (cost - x) + y);
					} else {
						cost += x;
					}
				}
				j = index - 1;
				ans += cost; // add the minimum cost of this row to the final answer
			}
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

