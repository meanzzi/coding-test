#include <iostream>
using namespace std;
#define MAX 1000000

int check[MAX + 1] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	check[0] = check[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		check[i] = i;
	}
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == 0) continue;
		for (int j = 2 * i; j <= MAX; j += i) {
			check[j] = 0;
		}
	}

	int t, n;
	cin >> t;
	while (t--) {
		int count = 0;
		cin >> n;
		for (int i = 2; i < n; i++) {
			if (check[i] + check[n - i] == n) {
				count++;
				if (i == n - i) count++; //5 5인 경우
			}
		}
		cout << count / 2 << '\n';
	}

	return 0;
}