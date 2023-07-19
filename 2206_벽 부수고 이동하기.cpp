#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Locate {
	int x;	//x좌표
	int y;	//y좌표
	int drill;	//길을 뚫은 적이 있는 지 없는지
};

int n, m;
int nx, ny, nd;
char map[1001][1001];
int visited[1001][1001][2];	//x좌표, y좌표, 방문체크(0: 안뚫은 세상 / 자연수: 몇 번째 방문인지)
queue<Locate> q;

int dx[4] = { 0, 0, -1, 1 };	//좌우상하
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
			if (map[to_x][to_y] == '0') {	//길이면서 
				if (nd == 0 && visited[to_x][to_y][0] == 0) {	//길을 한 번도 뚫은 적이 없을 때
					visited[to_x][to_y][0] = visited[nx][ny][0] + 1;
					q.push({ to_x, to_y, 0 });
				}
				else if(nd == 1 && visited[to_x][to_y][1] == 0) {	//길을 뚫었을 때
					visited[to_x][to_y][1] = visited[nx][ny][1] + 1;
					q.push({ to_x, to_y, 1 });

				}
			}
			if (map[to_x][to_y] == '1') {	//벽이면서
				if (nd == 0 && visited[to_x][to_y][0] == 0) {	//길을 한 번도 뚫은 적이 없을 때
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