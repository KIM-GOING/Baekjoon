#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct infoNum {
	int num;
	int count = 0;
};

int main() {
	int n;                                                                                                                                                                                                  
	cin >> n;
	vector<int> arr;	//숫자 저장 벡터
	vector<infoNum> arr2;	//최빈값 정보 저장 벡터
	int sum = 0;
	int max = -4000;
	int min = 4000;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sum += num;

		if (num > max)
			max = num;
		if (num < min)
			min = num;

		int check = 0;
		for (int i = 0; i < arr2.size(); i++) {
			if (arr2[i].num == num) {
				arr2[i].count++;
				check = 1;
				break;
			}
		}
		if (check == 0) {
			infoNum number;
			number.num = num;
			number.count++;
			arr2.push_back(number);
		}
		arr.push_back(num);
	}

	int ch1 = round((double)sum / (double)n);

	int ch3 = 0;
	vector<int> arr3;	//최빈값 중 최소 2값 저장 벡터
	int many = arr2[0].count;
	for (int i = 0; i < arr2.size(); i++) {
		if (arr2[i].count > many) {
			many = arr2[i].count;
			ch3 = arr2[i].num;
			for (int j = 0; j < arr3.size(); j++)
				arr3.pop_back();
			arr3.push_back(arr2[i].num);
		}
		else if (arr2[i].count == many) {
			if (arr3.size() == 0) {
				arr3.push_back(arr2[i].num);
				ch3 = arr3[0];
				continue;
			}
			else if (arr3.size() == 1) {
				arr3.push_back(arr2[i].num);
				if (arr3[1] < arr3[0]) {
					int temp = arr3[1];
					arr3[1] = arr3[0];
					arr3[0] = temp;
				}
				ch3 = arr3[1];
				continue;
			}
			if (arr2[i].num < arr3[0]) {
				arr3[1] = arr3[0];
				arr3[0] = arr2[i].num;
				ch3 = arr3[1];
				continue;
			}
			else if (arr2[i].num < arr3[1]) {
				arr3[1] = arr2[i].num;
				ch3 = arr3[1];
				continue;
			}
		}
	}

	int ch4 = max - min;

	sort(arr.begin(), arr.end());
	int ch2 = arr[n / 2];

	cout << ch1 << '\n' << ch2 << '\n' << ch3 << '\n' << ch4;

	return 0;
}