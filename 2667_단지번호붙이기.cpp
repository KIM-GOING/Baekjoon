#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Locate {
	int column;	//��
	int row;	//��
	int b;	//�ǹ� ����
};

int n;	//���� �� ���� ũ��
string line;
Locate arr[25][25];	//���� �迭
queue<Locate> q;	//bfs�� ���� ť
int d_c[4] = { -1, 1, 0, 0 };
int d_r[4] = { 0, 0, -1 ,1 };
int c, r;	//���� ��ġ�� ��� ��
int group;	//���� ��
int b_count = 1;	//���� �� �ǹ� ��
vector<int> groupArr;

void bfs() {

	while (!q.empty()) {
		c = q.front().column;
		r = q.front().row;

		q.pop();

		for (int u = 0; u < 4; u++) {
			int to_c = c + d_c[u];
			int to_r = r + d_r[u];

			if (to_c < 0 || to_r < 0 ||
				to_c >= n || to_r >= n)
				continue;
			else if (arr[to_c][to_r].b == 1) {
				q.push(arr[to_c][to_r]);
				b_count++;
				arr[to_c][to_r].b = 0;
			}

		}

	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//������ �ǹ� �ֱ�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			arr[i][j] = { i, j, (int)line[j] - 48};
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].b == 1) {
				q.push(arr[i][j]);
				arr[i][j].b = 0;
				group++;
				b_count = 1;
				bfs();
				groupArr.push_back(b_count);
			}
		}
	}

	sort(groupArr.begin(), groupArr.end());

	cout << group << '\n';
	for (int i = 0; i < group; i++)
		cout << groupArr[i] << '\n';

	return 0;
}