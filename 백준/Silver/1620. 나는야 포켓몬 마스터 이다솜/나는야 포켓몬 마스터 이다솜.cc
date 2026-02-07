#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string pokemon;
	map<string, int> test;

	cin >> n >> m;
	vector<string> number(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
		test.insert(make_pair(number[i], i));
	}
	
	for (int i = 0; i < m; i++) {
		cin >> pokemon;
		if (!isdigit(pokemon[0])) {
			auto it = test.find(pokemon);
			cout << it->second << '\n';
		}
		else {
			int num = stoi(pokemon);
			cout << number[num] << '\n';
		}
	}
	return 0;
}