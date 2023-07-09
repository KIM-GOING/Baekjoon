#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct tower {
	int index;
	int height;
};

int n;	//ž�� ��
vector<tower> tops;	//��� ž���� ����(�� ��°, ����)
vector<int> result;	//�� ž�� ��������
stack<tower> s;	//����

void func(tower t) {
	while (!s.empty()) {
		if (t.height > s.top().height) {
			s.pop();
		}
		else {
			result.push_back(s.top().index);
			s.push(t);
			break;
		}
	}
	if (s.empty()) {
		s.push(t);
		result.push_back(0);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		tops.push_back({ i + 1, h });	//���Ϳ� ž ���� ����
	}

	s.push(tops[0]);
	result.push_back(0);

	for (int i = 1; i < n; i++)
		func(tops[i]);

	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';

	return 0;
}