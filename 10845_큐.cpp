#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string action;
		cin >> action;

		if (action == "push") {
			int num;
			cin >> num;

			q.push(num);
		}

		if (action == "pop") {
			if (q.size() > 0) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << -1 << '\n';
		}

		if (action == "size")
			cout << q.size() << '\n';

		if (action == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		if (action == "front") {
			if (q.size() > 0)
				cout << q.front() << '\n';
			else
				cout << -1 << '\n';
		}

		if (action == "back") {
			if (q.size() > 0)
				cout << q.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}

	return 0;
}