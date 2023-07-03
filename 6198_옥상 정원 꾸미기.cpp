#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[80000] = { 0 };
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		arr[i] = height;
	}

	long long sum = 0;
	stack<int> search;
	search.push(arr[0]);
	for (int i = 1; i < n; i++) {
		while (search.size() != 0 && search.top() <= arr[i])
			search.pop();
		sum += search.size();
		search.push(arr[i]);
	}

	cout << sum;
	

	return 0;
}