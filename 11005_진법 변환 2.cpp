#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> number;	//변환진수(숫자) 담을 벡터
	int n, b;	//n: 10진수   b: 변환할 진법
	cin >> n >> b;

	//진법 변환
	int x = n;
	int y = 0;
	int num = x;
	int new_num;
	while (x >= b) {
		num = x;
		x = num / b;
		y = num % b;
		new_num = y;
		number.push_back(new_num);
	}
	number.push_back(x);

	char ch_num;
	int term = number.size();
	for (int i = 0; i < term; i++) {
		if (number[term-i-1] < 10)
			ch_num = char(number.back() + 48);
		else
			ch_num = char(number.back() + 55);
		cout << ch_num;
		number.pop_back();
	}

	return 0;
}