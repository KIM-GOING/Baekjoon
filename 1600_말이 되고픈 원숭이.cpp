#include <iostream>
#include <queue>
using namespace std;

struct Locate {
	int x;	//x��ǥ
	int y;	//y��ǥ
	int horse;	//�� �̵� ������� �� �� ����������
};

int k, w, h;
int nx, ny, nh;
int map[200][200];
int visited[200][200][31];	//x��ǥ, y��ǥ, �湮üũ(0: �ȶ��� ���� / �ڿ���: �� ��° �湮����)
queue<Locate> q;

int dx1[4] = { 0, 0, -1, 1 };	//������ ������ : �¿����
int dy1[4] = { -1, 1, 0, 0 };

int dx2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//�� ������ : �ð����
int dy2[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cin >> map[i][j];
	}

	//bfs()
	for (int i = 0; i < 31; i++)
		visited[0][0][i] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		nx = q.front().x;
		ny = q.front().y;
		nh = q.front().horse;

		if (nx == h - 1 && ny == w - 1) {
			cout << visited[nx][ny][nh] - 1;
			return 0;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {	//������ ������
			int to_x = nx + dx1[i];
			int to_y = ny + dy1[i];
			if (to_x < 0 || to_x >= h || to_y < 0 || to_y >= w || visited[to_x][to_y][nh] != 0)
				continue;
			
			if (map[to_x][to_y] == 0) {
				q.push({ to_x, to_y, nh });
				visited[to_x][to_y][nh] = visited[nx][ny][nh] + 1;
			}
		}

		for (int i = 0; i < 8; i++) {	//�� ������
			int to_x = nx + dx2[i];
			int to_y = ny + dy2[i];
			if (to_x < 0 || to_x >= h || to_y < 0 || to_y >= w || visited[to_x][to_y][nh + 1] != 0)
				continue;

			if (nh < k && map[to_x][to_y] == 0) {
				q.push({ to_x, to_y, nh + 1 });
				visited[to_x][to_y][nh + 1] = visited[nx][ny][nh] + 1;
			}
		}

	}

	cout << -1;

	return 0;
}