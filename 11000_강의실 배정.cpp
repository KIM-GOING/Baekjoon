#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct obj {	//���� �ð� ���� ����ü
	int start;
	int end;
};

bool cmp(obj a, obj b) {	//����ü ���� ���Լ�
	if (a.start < b.start)	//���۽ð� ����
		return true;
	else if (a.start == b.start)	//���۽ð� ���ٸ� ����ð� ����
		return a.end < b.end;
	else
		return a.start < b.start;
}

int n;	//���� ����
vector<obj> arr;	//���� ���� ����
priority_queue<int, vector<int>, greater<int>> pq;	//���� �ذ� �켱���� ť

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