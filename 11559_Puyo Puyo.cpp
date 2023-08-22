#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Locate {
	int x;
	int y;
};

char map[13][7];	//»Ñ¿ä¸Ê
int visited[13][7];	//¹æ¹®Ã³¸®
int result;	//¿¬¼â È½¼ö

int dx[4] = { 0, -1, 0 };	//ÁÂ »ó ¿ì
int dy[4] = { -1, 0, 1 };	//ÁÂ »ó ¿ì

void puyo() {
	//¹Ýº¹
	while (1) {
		int check = 0;	//»Ñ¿ä ½ÇÇàµÆ´ÂÁö

		//¿ÞÂÊ ¾Æ·¡ºÎÅÍ DFSÇÏ¸ç 4°³ ÀÌ»óÀÌ¸é ºóÄ­(.)
		for (int i = 12; i > 0; i--) {
			for (int j = 1; j <= 6; j++) {
				if (map[i][j] == '.') continue;
				else {
					vector<Locate> p;
					queue<Locate> q;

					p.push_back({ i, j });
					q.push({ i, j });
					visited[i][j] = 1;
					char color = map[i][j];

					while (!q.empty()) {
						int nowX = q.front().x;
						int nowY = q.front().y;
						q.pop();

						for (int k = 0; k < 3; k++) {
							int toX = nowX + dx[k];
							int toY = nowY + dy[k];

							if (toX < 1 || toX > 12 || toY < 1 || toY > 6 || visited[toX][toY] == 1)
								continue;
							if (map[toX][toY] == color) {
								p.push_back({ toX, toY });
								q.push({ toX, toY });
								visited[toX][toY] = 1;
							}
						}

					}

					if (p.size() >= 4) {
						for (int k = 0; k < p.size(); k++) {
							check = 1;
							map[p[k].x][p[k].y] = '.';
						}
					}
					for (int k = 0; k < p.size(); k++)
						visited[p[k].x][p[k].y] = 0;

				}
			}
		}

		//Áß·Â
		for (int j = 1; j <= 6; j++) {
			for (int i = 11; i >= 1; i--) {
				if (map[i][j] != '.') {
					int nowX = i;
					int nowY = j;

					while (1) {
						if (map[nowX + 1][nowY] == '.') {
							map[nowX + 1][nowY] = map[nowX][nowY];
							map[nowX][nowY] = '.';
							nowX = nowX + 1;
						}
						if (nowX == 12) break;
						if (map[nowX + 1][nowY] != '.') break;
					}
				}
			}
		}

		if (check == 1)
			result++;
		else
			return;

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 12; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= 6; j++) {
			map[i][j] = s[j-1];
		}
	}

	puyo();

	cout << result;

	return 0;
}