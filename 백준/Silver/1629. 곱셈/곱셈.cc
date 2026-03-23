#include <iostream>
using namespace std;

long long a, b, c;
long long power(long long a, long long b) {
	if (b == 0) return 1;
	long long temp = power(a, b / 2) % c;

	if (b % 2 == 0) {
		return (temp * temp) % c;
	}
	else {
		return (temp * temp % c) * a % c;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> a >> b >> c;
	cout << power(a,b);
	return 0;
}