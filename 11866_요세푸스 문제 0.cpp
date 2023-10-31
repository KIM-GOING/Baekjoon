#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int count = 1;
	int total = 1;

	cout << '<';

	while (!q.empty()) {
		if (count == k) {
			cout << q.front();
			q.pop();
			count = 0;
			if (total < n)
				cout << ", ";
			total++;
		}
		else {
			q.push(q.front());
			q.pop();
		}
		count++;
	}

	cout << '>';

	return 0;
}