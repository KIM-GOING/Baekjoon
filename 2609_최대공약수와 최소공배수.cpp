#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int max, min;
	if (n1 > n2) {
		max = n1;
		min = n2;
	}
	else {
		max = n2;
		min = n1;
	}

	//최대공약수
	vector<int> max_arr;
	vector<int> min_arr;

	for (int i = 1; i <= max; i++) {
		if (max % i == 0)
			max_arr.push_back(i);
	}
	for (int i = 1; i <= min; i++) {
		if (min % i == 0)
			min_arr.push_back(i);
	}

	int a_max = max_arr.back();
	max_arr.pop_back();
	int a_min = min_arr.back();
	min_arr.pop_back();
	int a_num = 0;
	while (1) {
		while (a_min < a_max) {
			a_max = max_arr.back();
			max_arr.pop_back();
		}
		while (a_max < a_min) {
			a_min = min_arr.back();
			min_arr.pop_back();
		}
		if (a_max == a_min) {
			a_num = a_max;
			break;
		}
	}

	//최소공배수
	int b_max = max;
	int b_min = min;
	int b_num = 0;
	while (1) {
		while (b_min < b_max) {
			b_min += min;
		}
		while (b_max < b_min) {
			b_max += max;
		}
		if (b_max == b_min) {
			b_num = b_max;
			break;
		}
	}

	cout << a_num << '\n' << b_num;

	return 0;
}