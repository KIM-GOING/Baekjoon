#include <iostream>
#include <queue>
using namespace std;

struct Bridge {	//사다리 정보
	int from;
	int to;
};

int n, m;
Bridge bridge[30] = { 0, };
queue<int> q;	//너비우선탐색
int now;	//현재 말의 위치
int nowCount;	//현재 위치까지 오는데의 주사위 던진 횟수
int visited[101] = { 0, };	//각 위치까지 오는것의 주사위 던진 횟수 저장
int v[101] = { 0, }; //방문체크

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n+m; i++) {	//연결통로 정보 저장
		int a, b;
		cin >> a >> b;
		bridge[i] = { a, b };
	}

	q.push(1);	//보드판은 1부터 시작
	v[1] = 1;
	while (v[100] != 1) {
		now = q.front();
		nowCount = visited[q.front()];
		q.pop();

		for (int i = 1; i <= 6; i++) {	//주사위를 6번 던질 때
			int check2 = 0;
			for (int j = 0; j < n + m; j++) {
				if (now + i == bridge[j].from) {
					q.push(bridge[j].to);
					if(visited[bridge[j].to] == 0)
						visited[bridge[j].to] = nowCount + 1;
					v[bridge[j].from] = 1;
					v[bridge[j].to] = 1;
					check2 = 1;
					break;
				}
			}

			if (check2 == 0 && v[now + i] == 0) {
				q.push(now + i);
				visited[now + i] = nowCount + 1;
				v[now + i] = 1;
			}
		}
	}

	cout << visited[100];

	return 0;
}