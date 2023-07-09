#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> arr;	//입력되는 수열 저장
stack<int> s;	//오큰수 함수를 위한 스택
stack<int> result;	//출력을 위한 스택

void nge(int num) {
	while (!s.empty()) {
		if (s.top() > num) {	//스택 top이 넣을 숫자보다 크다면
			result.push(s.top());	//스택 top 출력 (오큰수 발견)
			s.push(num);	//스택 원소 추가
			break;
		}
		else {
			s.pop();
		}
	}
	if (s.empty()) {
		s.push(num);
		result.push(-1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	s.push(arr.back());
	result.push(-1);
	arr.pop_back();

	for (int i = 1; i < n; i++) {
		nge(arr.back());
		arr.pop_back();
	}

	for (int i = 0; i < n; i++) {
		cout << result.top() << ' ';
		result.pop();
	}
		
	return 0;
}