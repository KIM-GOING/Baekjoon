#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;	//전체 용액 수
vector<long long> waters;	//용액들이 담긴 벡터배열
int f, c, e;	//세포인터 (front, center, end)

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

	sort(waters.begin(), waters.end());	//탐색을 위한 오름차순 정렬

	f = 0;
	e = waters.size() - 1;
	c

	return 0;
}