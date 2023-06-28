#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;
	vector<int> arr;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (arr.size() == 0)
				continue;
			else
				arr.pop_back();
		}
		else
			arr.push_back(num);
	}

	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	cout << sum;

	return 0;
}