#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t;	// test data

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int k = 0; k < t; k++) {
		string arr;
		cin >> arr;

		stack<char> s;	// parenthesis string
		int flag = 0;
		for (int i = 0; i < arr.size(); i++) {

			if (arr[i] == '(')
				s.push(arr[i]);

			if (arr[i] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = 1;
					break;
				}
				else {
					s.pop();
				}
			}

		}

		if (flag == 1 || !s.empty())
			cout << "NO\n";
		else
			cout << "YES\n";

	}

	return 0;
}