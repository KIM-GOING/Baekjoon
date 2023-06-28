#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> result;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		int first = n;
		int last = 2 * n;

		vector<int> arr = {0, 0};
		for (int i = 2; i <= last; i++) {
			arr.push_back(1);
		}
		for (int i = 2; i <= last; i++) {
			if (arr[i] == 0) continue;
			for (int j = i + i; j <= last; j += i) {
				arr[j] = 0;
			}
		}

		int count = 0;
		for (int i = first + 1; i <= last; i++) {
			if (arr[i] == 1)
				count++;
		}
		result.push_back(count);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

	return 0;
}