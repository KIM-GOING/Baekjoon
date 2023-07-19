#include <iostream>
#include <queue>
using namespace std;

struct Locate {
	int x;	//x좌표
	int y;	//y좌표
	int horse;	//말 이동 방법으로 몇 번 움직였는지
};

int k, w, h;
int nx, ny, nh;
int map[200][200];
int visited[200][200][31];	//x좌표, y좌표, 방문체크(0: 안뚫은 세상 / 자연수: 몇 번째 방문인지)
queue<Locate> q;

int dx1[4] = { 0, 0, -1, 1 };	//원숭이 움직임 : 좌우상하
int dy1[4] = { -1, 1, 0, 0 };

int dx2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//말 움직임 : 시계방향
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

		for (int i = 0; i < 4; i++) {	//원숭이 움직임
			int to_x = nx + dx1[i];
			int to_y = ny + dy1[i];
			if (to_x < 0 || to_x >= h || to_y < 0 || to_y >= w || visited[to_x][to_y][nh] != 0)
				continue;
			
			if (map[to_x][to_y] == 0) {
				q.push({ to_x, to_y, nh });
				visited[to_x][to_y][nh] = visited[nx][ny][nh] + 1;
			}
		}

		for (int i = 0; i < 8; i++) {	//말 움직임
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