#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct obj {	//강의 시간 정보 구조체
	int start;
	int end;
};

bool cmp(obj a, obj b) {	//구조체 정렬 비교함수
	if (a.start < b.start)	//시작시간 기준
		return true;
	else if (a.start == b.start)	//시작시간 같다면 종료시간 기준
		return a.end < b.end;
	else
		return a.start < b.start;
}

int n;	//수업 개수
vector<obj> arr;	//수업 저장 벡터
priority_queue<int, vector<int>, greater<int>> pq;	//문제 해결 우선순위 큐

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s,e });
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			pq.push(arr[i].end);
			continue;
		}

		if (arr[i].start >= pq.top()) {
			pq.pop();
			pq.push(arr[i].end);
		}
		else {
			pq.push(arr[i].end);
		}
	}

	cout << pq.size();

	return 0;
}