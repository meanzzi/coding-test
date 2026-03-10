#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long m;
	cin >> n >> m;

	vector<long long> tree(n);
	long long maxH = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		maxH = max(maxH, tree[i]);
	}

	long long left = 0, right = maxH, answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		if (sum >= m) {
			answer = mid;
			left = mid + 1; //더 높게 잘라도 되는지
		}
		else {
			right = mid - 1; //나무 부족해서 톱 낮춰서 자르기
		}
	}
	cout << answer;


	return 0;
}