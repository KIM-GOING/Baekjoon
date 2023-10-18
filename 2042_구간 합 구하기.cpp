#include <iostream>
#define N 1000000
using namespace std;

int n;	//�־��� ���� ����
int m;	//���� ���� Ƚ��
int k;	//���� �� ���ϴ� Ƚ��
long long nums[N + 1];
long long seg[N * 4];	//���� ���׸�Ʈ Ʈ�� ũ��� �־��� ������ 4���ϸ� ������

long long init(int start, int end, int node) {	//init(���� ���� �ε���, ���� �ε���, �����ġ)
	if (start == end)
		return seg[node] = nums[start];
	
	int mid = (start + end) / 2;
	return seg[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, long long num) {
	if (start > idx || end < idx) return;

	if (start == idx && end == idx) {
		seg[node] = num;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, num);
	update(mid + 1, end, node * 2 + 1, idx, num);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long sum(int start, int end, int node, int left, int right) {
	if (start > right || end < left) return 0;

	if (start >= left && end <= right)
		return seg[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		if (a == 1)
			update(1, n, 1, b, c);
		else
			cout << sum(1, n, 1, b, c) << '\n';
	}

	return 0;
}