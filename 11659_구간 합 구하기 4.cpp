#include <iostream>
using namespace std;

struct Prefix_sum {
	int num;
	int sum = 0;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	Prefix_sum* arr = new Prefix_sum[n+1];
	Prefix_sum n1;
	n1.num = 0;
	n1.sum = 0;
	arr[0] = n1;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		Prefix_sum number;
		int n;
		cin >> n;
		number.num = n;
		s += n;
		number.sum = s;
		arr[i] = number;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << arr[j].sum - arr[i-1].sum << '\n';
	}

	delete[] arr;
	return 0;
}