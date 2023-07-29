#include <iostream>
#include <queue>
using namespace std;

struct Locate {
	int x;
	int y;
};

int n;	//霸烙备开狼 农扁
int map[3][3];	//备开(甘)
int visited[3][3];
queue<Locate> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	q.push({ 0,0 });
	visited[0][0] = 1;

	int check = 0;
	while (!q.empty()) {
		int nowX = q.front().x;
		int nowY = q.front().y;
		int to = map[nowX][nowY];

		int dx[2] = { nowX, nowX + to };
		int dy[2] = { nowY + to, nowY };

		q.pop();

		for (int i = 0; i < 2; i++) {
			if (dx[i] < n && dy[i] < n && visited[dx[i]][dy[i]] == 0) {
				q.push({ dx[i], dy[i] });
				visited[dx[i]][dy[i]] = 1;
				if (map[dx[i]][dy[i]] == -1)
					check = 1;
			}
		}
	}

	if (check == 1)
		cout << "HaruHaru";
	else
		cout << "Hing";

	return 0;
}