#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n;
string word;
deque<int> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;

		if (word == "push_front") {
			int num;
			cin >> num;
			d.push_front(num);
		}

		if (word == "push_back") {
			int num;
			cin >> num;
			d.push_back(num);
		}

		if (word == "pop_front") {
			if (d.size() > 0) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else
				cout << -1 << '\n';
		}

		if (word == "pop_back") {
			if (d.size() > 0) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else
				cout << -1 << '\n';
		}

		if (word == "size")
			cout << d.size() << '\n';

		if (word == "empty")
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';

		if (word == "front")
			if (d.size() > 0)
				cout << d.front() << '\n';
			else
				cout << -1 << '\n';

		if (word == "back")
			if (d.size() > 0)
				cout << d.back() << '\n';
			else
				cout << -1 << '\n';
	}

	return 0;
}