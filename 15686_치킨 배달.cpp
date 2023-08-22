#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Locate {
	int x;
	int y;
};

int n; //도시 크기
int m; //치킨집 개수
int result = 51;
int map[51][51];
int visited[51][51];
vector<Locate> home;
vector<Locate> chicken;
vector<Locate> chosen;

void back(int total, int index) {
	if (total == m) {
		int Min = 0;

		for (int i = 0; i < home.size(); i++) {
			int dis = 51;
			for (int j = 0; j < chosen.size(); j++) {
				int disX = abs(chosen[j].x - home[i].x);
				int disY = abs(chosen[j].y - home[i].y);

				dis = min(dis, disX+disY);
			}
			Min += dis;
		}
		result = min(result, Min);
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		int nowx = chicken[i].x;
		int nowy = chicken[i].y;

		if (chicken.size() - i < m - total) return;
		if (visited[nowx][nowy] == 1) continue;

		visited[nowx][nowy] = 1;
		chosen.push_back(chicken[i]);

		back(total + 1, total + 1);
		chosen.pop_back();
		visited[nowx][nowy] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back({ i, j });
			else if (map[i][j] == 2)
				chicken.push_back({ i, j });
		}

	back(0, 0);

	cout << result;

	return 0;
}