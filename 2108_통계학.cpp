#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct infoNum {
	int num;
	int count = 0;
};

bool info(infoNum a, infoNum b) {
	if (a.count == b.count) {
		return a.num < b.num;
	}
	return a.count > b.count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;                                                                                                                                                                                                  
	cin >> n;
	vector<int> arr;	//숫자 저장 벡터
	vector<infoNum> arr2;	//최빈값 정보 저장 벡터
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sum += num;


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

	//산술평균
	int ch1 = round((double)sum / (double)n);

	//최빈값
	sort(arr2.begin(), arr2.end(), info);
	int ch3 = 0;
	if (arr2.size() == 1)
		ch3 = arr2[0].num;
	else {
		if (arr2[0].count != arr2[1].count)
			ch3 = arr2[0].num;
		else
			ch3 = arr2[1].num;
	}

	//중간값
	sort(arr.begin(), arr.end());
	int ch2 = arr[n / 2];

	int ch4 = arr.back() - arr.front();

	cout << ch1 << '\n' << ch2 << '\n' << ch3 << '\n' << ch4;

	return 0;
}