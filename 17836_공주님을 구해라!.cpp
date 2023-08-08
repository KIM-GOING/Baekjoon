#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Locate {
	int x;
	int y;
	int sword = 0;	//칼을 주웠는지 안 주웠는지 체크
	int hour = 0;	//현재 위치까지 왔을때의 걸린 시간
};

int n, m, t;
int result;	//도착지까지 걸린 시간
int map[105][105];
int visited[105][105][2];	//칼 안 먹은 세계(0), 먹은 세계(1)
queue<Locate> q;	//너비우선탐색 큐

int dx[4] = { 0, 1, 0, -1 };	//우, 하, 좌, 상
int dy[4] = { 1, 0, -1, 0 };	//우, 하, 좌, 상

void bfs() {
	
	while (!q.empty()) {
		int nowX = q.front().x;	//현재 x위치 (x,y)
		int nowY = q.front().y;	//현재 y위치 (x,y)
		int nowS = q.front().sword;	//현재 칼 획득 여부
		int nowH = q.front().hour;	//현재까지 이동 걸린 시간

		if (nowX == n - 1 && nowY == m - 1) {	//마지막 위치에 도착하면
			result = nowH;
			break;
		}

		q.pop();

		for (int u = 0; u < 4; u++) {
			int toX = nowX + dx[u];	//이동할 x좌표
			int toY = nowY + dy[u];	//이동할 y좌표

			if (toX < 0 || toX >= n || toY < 0 || toY >= m) continue;

			if (nowS == 0 && visited[toX][toY][0] == 0) {	//검 안 먹었으면서 방문 안했을 때
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