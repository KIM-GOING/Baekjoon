#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
stack<int> s;

int main() {

	cin >> n;
	for (int a = 0; a < n; a++) {
		string request;
		cin >> request;

		if (request == "push") {
			int num1;
			cin >> num1;
			s.push(num1);
		}

		if (request == "pop") {
			if (s.size() == 0) 
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}

		if (request == "size") 
			cout << s.size() << '\n';
		
		if (request == "empty") {
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		if (request == "top") {
			if (s.size() == 0)
				cout << -1 << '\n';
			else 
				cout << s.top() << '\n';
		}
	}

	return 0;
}