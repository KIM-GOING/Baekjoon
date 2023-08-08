#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Locate {
	int x;
	int y;
	int sword = 0;	//Į�� �ֿ����� �� �ֿ����� üũ
	int hour = 0;	//���� ��ġ���� �������� �ɸ� �ð�
};

int n, m, t;
int result;	//���������� �ɸ� �ð�
int map[105][105];
int visited[105][105][2];	//Į �� ���� ����(0), ���� ����(1)
queue<Locate> q;	//�ʺ�켱Ž�� ť

int dx[4] = { 0, 1, 0, -1 };	//��, ��, ��, ��
int dy[4] = { 1, 0, -1, 0 };	//��, ��, ��, ��

void bfs() {
	
	while (!q.empty()) {
		int nowX = q.front().x;	//���� x��ġ (x,y)
		int nowY = q.front().y;	//���� y��ġ (x,y)
		int nowS = q.front().sword;	//���� Į ȹ�� ����
		int nowH = q.front().hour;	//������� �̵� �ɸ� �ð�

		if (nowX == n - 1 && nowY == m - 1) {	//������ ��ġ�� �����ϸ�
			result = nowH;
			break;
		}

		q.pop();

		for (int u = 0; u < 4; u++) {
			int toX = nowX + dx[u];	//�̵��� x��ǥ
			int toY = nowY + dy[u];	//�̵��� y��ǥ

			if (toX < 0 || toX >= n || toY < 0 || toY >= m) continue;

			if (nowS == 0 && visited[toX][toY][0] == 0) {	//�� �� �Ծ����鼭 �湮 ������ ��
				if (map[toX][toY] == 0) {
					visited[toX][toY][0] = 1;
					q.push({ toX, toY, 0, nowH + 1 });
				}
				if (map[toX][toY] == 2) {
					visited[toX][toY][1] = 1;
					q.push({ toX, toY, 1, nowH + 1 });
				}
			}
			
			if (nowS == 1 && visited[toX][toY][1] == 0) {
				visited[toX][toY][1] = 1;
				q.push({ toX, toY, 1, nowH + 1 });
			}
		}

	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0, 0 });

	bfs();

	if (result > t || result == 0)
		cout << "Fail";
	else
		cout << result;

	return 0;
}