#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;	//��ü ��� ��
vector<long long> waters;	//��׵��� ��� ���͹迭
int p, f, e;	//�б���, ��������(front, end)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long water;
		cin >> water;
		waters.push_back(water);
	}

	sort(waters.begin(), waters.end());

	return 0;
}