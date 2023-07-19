#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Locate {
	int x;	//x��ǥ
	int y;	//y��ǥ
	int drill;	//���� ���� ���� �ִ� �� ������
};

int n, m;
int nx, ny, nd;
char map[1001][1001];
int visited[1001][1001][2];	//x��ǥ, y��ǥ, �湮üũ(0: �ȶ��� ���� / �ڿ���: �� ��° �湮����)
queue<Locate> q;

int dx[4] = { 0, 0, -1, 1 };	//�¿����
int dy[4] = { -1, 1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	//bfs()
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		nx = q.front().x;
		ny = q.front().y;
		nd = q.front().drill;

		if (nx == n - 1 && ny == m - 1) {
			cout << visited[nx][ny][nd];
			return 0;
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int to_x = nx + dx[i];
			int to_y = ny + dy[i];
			if (to_x < 0 || to_x >= n || to_y < 0 || to_y >= m || visited[to_x][to_y][nd] != 0)
				continue;
			if (map[to_x][to_y] == '0') {	//���̸鼭 
				if (nd == 0 && visited[to_x][to_y][0] == 0) {	//���� �� ���� ���� ���� ���� ��
					visited[to_x][to_y][0] = visited[nx][ny][0] + 1;
					q.push({ to_x, to_y, 0 });
				}
				else if(nd == 1 && visited[to_x][to_y][1] == 0) {	//���� �վ��� ��
					visited[to_x][to_y][1] = visited[nx][ny][1] + 1;
					q.push({ to_x, to_y, 1 });

				}
			}
			if (map[to_x][to_y] == '1') {	//���̸鼭
				if (nd == 0 && visited[to_x][to_y][0] == 0) {	//���� �� ���� ���� ���� ���� ��
					visited[to_x][to_y][1] = visited[nx][ny][0] + 1;
					q.push({ to_x, to_y, 1 });
				}
			}

			/*if (map[to_x][to_y] == '0') {
				visited[to_x][to_y][nd] = visited[nx][ny][nd] + 1;
				q.push({ to_x, to_y, nd });

			}
			else {
				if (nd == 0) {
					visited[to_x][to_y][nd+1] = visited[nx][ny][nd] + 1;
					q.push({ to_x, to_y, nd+1 });
				}
			}*/
		}

	}

	cout << -1;
	

	



	return 0;
}