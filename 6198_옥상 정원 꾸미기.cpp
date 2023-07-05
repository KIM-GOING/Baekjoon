#include <iostream>
#include <stack>
using namespace std;

int arr[80000];
stack<int> search;
long long sum = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		arr[i] = height;
	}
	
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