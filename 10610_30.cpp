#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string n;
int sum, result, check;
vector<int> arr;

int fx(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		sum += (int)n[i] - 48;	//각 자리수의 합이 3의 배수인지 판별하기 위해 다 더함
		arr.push_back((int)n[i] - 48);	//자리 숫자 정렬을 위해 벡터에 넣음
		if ((int)n[i] - 48 == 0)	//30의 배수 조건인 0의 유무를 알기 위한 단계
			check = 1;
	}
	if (sum % 3 != 0 || check == 0) {		//30의 배수가 안되는 조건
		cout << -1;
		return 0;
	}
	else {
		sort(arr.begin(), arr.end(), fx);	//내림차순 정렬
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
		return 0;
	}
}