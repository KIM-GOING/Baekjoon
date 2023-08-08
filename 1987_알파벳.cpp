#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Locate {
	int x;
	int y;
};

int r, c;
int m;	//�ִ� �̵� ĭ ��
char map[20][20];	//���ĺ��� �� �ִ� ���
int visited[20][20];	//�湮üũ ���
vector<char> alpha;	//���̿켱Ž�� ���

int dx[4] = { 0, 1, 0, -1 };	//�� : ��, ��, ��, ��
int dy[4] = { 1, 0, -1, 0 };	//�� : ��, ��, ��, ��

void DFS(Locate a) {	//��͸� ����� ���̿켱Ž��
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