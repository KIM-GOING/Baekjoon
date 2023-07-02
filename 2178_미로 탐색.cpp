#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Position {
	int x = 0;
	int y = 0;
	int visit = 1;
	int count = 0;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	Position** maze = new Position *[n];
	for (int i = 0; i < n; i++)
		maze[i] = new Position[m];

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			Position p;
			p.x = i;
			p.y = j;
			p.visit = (int)row[j] - 48;
			maze[i][j] = p;
		}
	}

	Position exit;
	exit.x = n - 1;
	exit.y = m - 1;
	queue<Position> arr;
	maze[0][0].count = 1;
	Position now = maze[0][0];
	arr.push(now);
	now.visit = 0;
	while (arr.front().x != exit.x || arr.front().y != exit.y) {
		if (now.x - 1 >= 0)
			if (maze[now.x - 1][now.y].visit == 1) {
				maze[now.x - 1][now.y].count = now.count + 1;
				arr.push(maze[now.x - 1][now.y]);
			}
		if (now.y - 1 >= 0)
			if (maze[now.x][now.y - 1].visit == 1) {
				maze[now.x][now.y - 1].count = now.count + 1;
				arr.push(maze[now.x][now.y - 1]);
			}
		if (now.x + 1 < n)
			if (maze[now.x + 1][now.y].visit == 1) {
				maze[now.x + 1][now.y].count = now.count + 1;
				arr.push(maze[now.x + 1][now.y]);
			}
		if (now.y + 1 < m)
			if (maze[now.x][now.y + 1].visit == 1) {
				maze[now.x][now.y + 1].count = now.count + 1;
				arr.push(maze[now.x][now.y + 1]);
			}
		arr.pop();
		now = arr.front();
		arr.push(now);
		now.visit = 0;
	}

	cout << arr.front().count << '\n';

	for(int i = 0; i < n; i++)
		delete[] maze[i];
	delete[] maze;
	return 0;
}