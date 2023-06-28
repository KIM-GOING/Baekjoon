#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr1.push_back(num);
	}
	sort(arr1.begin(), arr1.end());

	int m;
	cin >> m;
	vector<int> arr2;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr2.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		bool result = binary_search(arr1.begin(), arr1.end(), arr2[i]);
		if (result == true)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}