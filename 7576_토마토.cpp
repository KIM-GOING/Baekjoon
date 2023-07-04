#include <iostream>
#include <queue>
using namespace std;

struct Locate {
	int x, y;
};

Locate tempL;
Locate map[1001][1001];
int tomato[1001][1001] = { -1, };
int visit[1001][1001];
queue<Locate> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Locate l;
			l.x = i;
			l.y = j;
			map[i][j] = l;

			int t;
			cin >> t;
			tomato[i][j] = t;
			if (t == 1) {
				visit[i][j] = 0;
				q.push(l);
			}
		}
	}

	while (q.size() != 0) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x - 1 >= 0 && tomato[x - 1][y] == 0) {
			visit[x - 1][y] = visit[x][y] + 1;
			tomato[x - 1][y] = 1;
			q.push(map[x - 1][y]);
		}
		if (x + 1 < m && tomato[x + 1][y] == 0) {
			visit[x + 1][y] = visit[x][y] + 1;
			tomato[x + 1][y] = 1;
			q.push(map[x + 1][y]);
		}
		if (y - 1 >= 0 && tomato[x][y - 1] == 0) {
			visit[x][y - 1] = visit[x][y] + 1;
			tomato[x][y - 1] = 1;
			q.push(map[x][y - 1]);
		}
		if (y + 1 < n && tomato[x][y + 1] == 0) {
			visit[x][y + 1] = visit[x][y] + 1;
			tomato[x][y + 1] = 1;
			q.push(map[x][y + 1]);
		}
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (count < visit[i][j])
				count = visit[i][j];
		}
	}
	cout << count;
	return 0;
}