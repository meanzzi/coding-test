#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> op;
int main() {
	string ntt;
	cin >> ntt;
	for (int i = 0; i < ntt.size(); i++) {
		if (ntt[i] >= 'A' && ntt[i] <= 'Z') {
			cout << ntt[i];
		}
		else {
			if (ntt[i] == '(') {
				op.push(ntt[i]);
			}
			else if (ntt[i] == '*' || ntt[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(ntt[i]);
			}
			else if (ntt[i] == '+' || ntt[i] == '-') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(ntt[i]);
			}
			else if (ntt[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}

	return 0;
}