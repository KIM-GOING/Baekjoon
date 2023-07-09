#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct tower {
	int index;
	int height;
};

int n;	//탑의 수
vector<tower> tops;	//모든 탑들의 정보(몇 번째, 높이)
vector<int> result;	//각 탑의 수신정보
stack<tower> s;	//스택

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
		tops.push_back({ i + 1, h });	//벡터에 탑 정보 저장
	}

	s.push(tops[0]);
	result.push_back(0);

	for (int i = 1; i < n; i++)
		func(tops[i]);

	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';

	return 0;
}