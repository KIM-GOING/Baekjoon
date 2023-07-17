#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;	//용액의 수
vector<int> arr;	//용액 담을 배열
int f, e;	//투포인터
int result;	//0에 가까운 수
int first, last;	//0에 가까울 때 두 수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	f = 0;
	e = n - 1;

	result = abs(arr[0] + arr[n - 1]);
	first = arr[0];
	last = arr[n - 1];

	while (f != e) {
		if (abs(arr[f] + arr[e]) < result) {
			result = abs(arr[f] + arr[e]);
			first = arr[f];
			last = arr[e];
		}
		if (arr[f] + arr[e] > 0)
			e--;
		else
			f++;
	}

	cout << first << ' ' << last;

	return 0;
}