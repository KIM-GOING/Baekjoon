#include <iostream>
using namespace std;

int n, m;
int r, c, d;
int arr[51][51];
int now_r, now_c, now_d;
int cleanCount;
int finish;


void clean(int x, int y) {
	if (arr[x][y] == 0) {
		arr[x][y] = 2;
		cleanCount++;
	}
}

void all_clean(int x, int y, int dir) {

	int ddir[4] = { x + 1, y - 1, x - 1, y + 1 };
	int dx[4] = { x + 1, x, x - 1, x };
	int dy[4] = { y, y - 1, y, y + 1 };

	if (arr[dx[dir]][dy[dir]] == 1) {
		finish = 1;
		return;
	}

	else if (arr[dx[dir]][dy[dir]] == 0 || arr[dx[dir]][dy[dir]] == 2) {
		now_r = dx[dir];
		now_c = dy[dir];
		now_d = dir;
	}

}

void search(int x, int y, int dir) {

	int ddir[4] = { x - 1, y + 1, x + 1, y - 1 };
	int dx[4] = { x - 1, x, x + 1, x };
	int dy[4] = { y, y + 1, y, y - 1 };

	for (int u = dir + 3; u > dir - 1; u--) {
		int i;
		if (u > 3)
			i = u - 4;
		else
			i = u;

		if (arr[dx[i]][dy[i]] == 0) {
			clean(dx[i], dy[i]);
			now_r = dx[i];
			now_c = dy[i];
			now_d = i;
			return;
		}
	}

	all_clean(x, y, dir);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	now_r = r;
	now_c = c;
	now_d = d;

	while (finish != 1) {
		clean(now_r, now_c);
		search(now_r, now_c, now_d);
	}

	cout << cleanCount;

	return 0;
}