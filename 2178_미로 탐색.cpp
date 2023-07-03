#include <iostream>
#include <string>
#include <queue>
using namespace std;

//큐에 넣을 위치 구조체 정의
struct Position {
	int x = 0;
	int y = 0;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	Position maze[100][100];
	int visit[100][100];
	int count[100][100] = {0};


	//미로 입력
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			Position p;
			p.x = i;
			p.y = j;
			maze[i][j] = p;
			visit[i][j] = (int)row[j] - 48;
		}
	}

	queue<Position> arr;
	Position now = maze[0][0];

	visit[0][0] = 0;
	count[0][0] = 1;
	arr.push(now);
	while (now.x != n - 1 || now.y != m - 1) {
		int x = now.x;
		int y = now.y;

		if(x - 1 >= 0)
			if (visit[x - 1][y] == 1) {
				visit[x - 1][y] = 0;
				arr.push(maze[x - 1][y]);
				count[x - 1][y] = count[x][y] + 1;
			}
		if(x + 1 < n)
			if (visit[x + 1][y] == 1) {
				visit[x + 1][y] = 0;
				arr.push(maze[x + 1][y]);
				count[x + 1][y] = count[x][y] + 1;
			}
		if(y - 1 >= 0)
			if (visit[x][y - 1] == 1) {
				visit[x][y - 1] = 0;
				arr.push(maze[x][y - 1]);
				count[x][y - 1] = count[x][y] + 1;
			}
		if (y + 1 < m)
			if (visit[x][y + 1] == 1) {
				visit[x][y + 1] = 0;
				arr.push(maze[x][y + 1]);
				count[x][y + 1] = count[x][y] + 1;
			}
		arr.pop();
		now = arr.front();
	}

	cout << count[n - 1][m - 1];

	return 0;
}