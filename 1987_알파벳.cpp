#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Locate {
	int x;
	int y;
};

int r, c;
int m;	//최대 이동 칸 수
char map[20][20];	//알파벳이 들어가 있는 행렬
int visited[20][20];	//방문체크 행렬
vector<char> alpha;	//깊이우선탐색 경로

int dx[4] = { 0, 1, 0, -1 };	//열 : 우, 하, 좌, 상
int dy[4] = { 1, 0, -1, 0 };	//행 : 우, 하, 좌, 상

void DFS(Locate a) {	//재귀를 사용한 깊이우선탐색
	int nowX = a.x;
	int nowY = a.y;

	visited[nowX][nowY] = 1;
	alpha.push_back(map[nowX][nowY]);
	if (m < alpha.size())
		m = alpha.size();

	for (int u = 0; u < 4; u++) {
		int toX = nowX + dx[u];
		int toY = nowY + dy[u];

		if (toX < 0 || toX >= r || toY < 0 || toY >= c 
			|| visited[toX][toY] == 1)	continue;

		int check = 0;
		for (int i = 0; i < alpha.size(); i++)
			if (map[toX][toY] == alpha[i]) {
				check = 1;
				break;
			}

		if(check == 0)
			DFS({ toX, toY });

	}

	visited[nowX][nowY] = 0;
	alpha.pop_back();

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < c; j++)
			map[i][j] = line[j];
	}

	DFS({ 0, 0 });

	cout << m;

	return 0;
}