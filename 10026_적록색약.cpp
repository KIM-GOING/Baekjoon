#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Locate {
	int column;
	int row;
};

int n;
int c = 0;
char picture[100][100] = { '.',};	//그림(RGB 정보)
int visited[100][100] = { 0, };	//방문체크
queue<Locate> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			picture[i][j] = line[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				q.push({ i, j });
				visited[i][j] = 1;

				while (!q.empty()) {
					int x = q.front().column;
					int y = q.front().row;

					q.pop();

					for (int u = 0; u < 4; u++) {
						if (x + dx[u] < 0 || x + dx[u] >= n || y + dy[u] < 0 || y + dy[u] >= n)
							continue;
						else if (visited[x + dx[u]][y + dy[u]] == 0 &&
							picture[x][y] == picture[x + dx[u]][y + dy[u]]) {
							q.push({ x + dx[u], y + dy[u] });
							visited[x + dx[u]][y + dy[u]] = 1;
						}
					}
				}

				c++;
			}
		}
	}
	cout << c << ' ';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	c = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				q.push({ i, j });
				visited[i][j] = 1;
				
				while (!q.empty()) {
					int x = q.front().column;
					int y = q.front().row;

					q.pop();

					for (int u = 0; u < 4; u++) {
						if (x + dx[u] < 0 || x + dx[u] >= n || y + dy[u] < 0 || y + dy[u] >= n)
							continue;
						else if (visited[x + dx[u]][y + dy[u]] == 0) {
							if (picture[x][y] == 'G' && picture[x + dx[u]][y + dy[u]] == 'R' ||
								picture[x][y] == 'R' && picture[x + dx[u]][y + dy[u]] == 'G' ||
								picture[x][y] == picture[x + dx[u]][y + dy[u]]) {
								q.push({ x + dx[u], y + dy[u] });
								visited[x + dx[u]][y + dy[u]] = 1;
							}
						}
					}
				}

				c++;
			}
		}
	}
	cout << c << ' ';

	return 0;
}