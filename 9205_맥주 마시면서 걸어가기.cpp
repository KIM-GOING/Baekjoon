#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Locate {
	int x_loc = 0;
	int y_loc = 0;
};

int t, n, r;
vector<Locate> arr;
queue<Locate> route;	//BFS를 위한 큐
int visited[103] = { 0, };	//방문 안했으면 0, 했으면 1

int dist(Locate a, Locate b) {	//맨해튼 거리 구하는 함수
	return abs(a.x_loc - b.x_loc) + abs(a.y_loc - b.y_loc);
}

int bfs() {
	while (route.size() != 0) {
		Locate now = { route.front().x_loc, route.front().y_loc };

		route.pop();

		for (int i = 0; i < arr.size(); i++) {
			if (visited[i] == 1)
				continue;
			else {
				if (dist(now, arr[i]) <= 1000) {
					route.push(arr[i]);
					visited[i] = 1;
				}
			}
		}

		if (route.front().x_loc == arr.back().x_loc &&
			route.front().y_loc == arr.back().y_loc) {
			r = 1;
			break;
		}
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int u = 0; u < t; u++) {
		for (int i = 0; i < n; i++)
			visited[i] = 0;
		arr.clear();
		while (!route.empty())
			route.pop();
		r = 0;

		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			arr.push_back({ x, y });	//좌표 배열에 위치 입력하기
		}

		route.push(arr[0]);
		visited[0] = 1;

		if (bfs() == 1)
			cout << "happy\n";
		else
			cout << "sad\n";

	}

	return 0;
}