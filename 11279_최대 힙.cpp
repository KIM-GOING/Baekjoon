#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> arr;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int u = 0; u < n; u++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (arr.size() == 0)
				cout << 0 << '\n';
			else {
				cout << arr.top() << '\n';
				arr.pop();
			}
		}

		else {
			arr.push(x);
		}

	}

	return 0;
}