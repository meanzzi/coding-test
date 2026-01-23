#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, k;
	string num;
	deque<char> big;

	cin >> n >> k;
	cin >> num;
	int sum = n - k;
	for (int i = 0; i < n; i++) {
		while (k != 0 && !big.empty() && big.back() < num[i]) {
			big.pop_back();
			k--;
		}
		big.push_back(num[i]);
	}
	for (int i = 0; i < sum; i++) {
		cout << big[i];
	}
	// 큰 수 들어오면 계속 pop -> k개만큼

	return 0;
}