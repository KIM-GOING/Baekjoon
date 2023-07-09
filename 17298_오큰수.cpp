#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> arr;	//�ԷµǴ� ���� ����
stack<int> s;	//��ū�� �Լ��� ���� ����
stack<int> result;	//����� ���� ����

void nge(int num) {
	while (!s.empty()) {
		if (s.top() > num) {	//���� top�� ���� ���ں��� ũ�ٸ�
			result.push(s.top());	//���� top ��� (��ū�� �߰�)
			s.push(num);	//���� ���� �߰�
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