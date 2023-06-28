#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> weight;
	vector<int> height;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		weight.push_back(x);
		height.push_back(y);
	}

	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 0; j < n; j++) {
			if (weight[i] < weight[j]) {
				if (height[i] < height[j])
					count++;
			}
		}
		cout << count << ' ';
	}

	return 0;
}