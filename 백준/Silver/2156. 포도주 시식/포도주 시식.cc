#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, wine[10009] = { 0, }, dp[10009] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1]; //1잔일때 최대
	dp[2] = wine[1] + wine[2]; // 2잔일때 최대
	dp[3] = max({ wine[1] + wine[3], wine[2] + wine[3], dp[2] }); //3잔
	for (int i = 4; i <= n; i++) {
		dp[i] = max({ dp[i - 2] + wine[i], dp[i - 1], dp[i - 3] + wine[i - 1] + wine[i] });
	}

	cout << dp[n] << '\n';

	return 0;
}